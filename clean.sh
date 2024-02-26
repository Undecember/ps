#!/bin/bash

read -p "Do you really want to clean every code? [y/N] " response

case "$response" in
    [yY][eE][sS]|[yY])
        rm -rf boj/*
        find codeforces/ -type f -name '*.cpp' -exec rm {} +
        echo "All codes have been cleaned."
        ;;
    *)
        ;;
esac
