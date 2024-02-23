#!/bin/bash

cf_tool_url="https://github.com/dianhsu-official/cf-tool/releases/download/v1.0.9/cf_linux_x64.zip"

download_cf_tool() {
    echo "Downloading cf tool..."
    wget -q $cf_tool_url -O cf_tool.zip
    echo "Unzipping cf tool..."
    unzip -q cf_tool.zip
    echo "Moving cf to ./bin"
    mv cf ./bin/cf
    echo "Cleaning up..."
    rm -f cf_tool.zip
    echo "Setting up config..."
    mkdir -p ~/.cf
    cp ./bin/config ~/.cf/config
    sed -i 's|PWD|'"$(pwd)"'|g' ~/.cf/config
    echo "Complete."
}

# setup cf tool
if [ ! -f "./bin/cf" ]; then
    download_cf_tool
fi
alias cf="$(pwd)/bin/cf"

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
