#!/bin/bash

# check dependency
for cmd in "cmake" "g++" "wget"; do
    if ! command -v $cmd &> /dev/null; then
        echo "[fatal] $cmd is not installed. Install it with apt and retry later."
        exit 1
    fi
done

cf_tool_url="https://github.com/dianhsu-official/cf-tool/releases/download/v1.0.9/cf_linux_x64.zip"

download_cf_tool() {
    echo "Downloading cf tool..."
    mkdir -p ./bin
    mkdir -p ./bin/cf_tool
    wget -q $cf_tool_url -O cf_tool.zip
    echo "Unzipping cf tool..."
    unzip -q cf_tool.zip
    echo "Moving cf to ./bin/cf_tool"
    mv cf ./bin/cf_tool/
    echo "Cleaning up..."
    rm -f cf_tool.zip
    echo "Setting up config..."
    mkdir -p ~/.cf
    cp ./resources/config ~/.cf/config
    sed -i 's|PWD|'"$(pwd)"'|g' ~/.cf/config
    echo "Complete."
}

# setup cf tool
if [ ! -f "./bin/cf_tool/cf" ]; then
    download_cf_tool
fi
alias cf="$(pwd)/bin/cf_tool/cf"

build_boj_tool() {
    mkdir -p ./bin
    mkdir -p ./bin/boj_tool
    cd ./bin/boj_tool
    echo "Configuring boj tool..."
    cmake ../../boj_tool
    echo "Building boj tool..."
    make -j$(nproc)
    cd ../..
    echo "Complete."
}

# setup boj tool
if [ ! -f "./bin/boj_tool/boj" ]; then
    build_boj_tool
fi
alias boj="$(pwd)/bin/boj_tool/boj $(pwd)/bin/cf_tool/cf"

# setup PS
PS1_OLD=$PS1
export PS1="(ps) $PS1"

# setup deactivate function
deactivate() {
    unset -f deactivate
    alias cf=
    export PS1=$PS1_OLD
    echo "Environment deactivated."
}
