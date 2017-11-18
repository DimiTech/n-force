#!/bin/bash

size=1
number=2

n_force () {
    clear
    echo "${size}x${number}"
    ./n_force $(echo "${size} ${number}")
    size=$(( size + 1 ))
    if [ $(( size * number )) -ge 50 ]; then
        number=$(( number + 1 ))
        size=1
    fi
    if [ $(( size * number )) -ge 50 ]; then
        number=2
    fi
    sleep 0.2
    n_force
}

n_force

