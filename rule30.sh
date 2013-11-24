#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
g++ -I/Users/thahn/utils/homebrew/include -L/Users/thahn/utils/homebrew/lib/ -I/Users/thahn/utils/irrKlang/include -L/Users/thahn/utils/irrKlang/bin/macosx-gcc -lgd -lirrklang -arch i386  *.cpp -o bin/rule30
cd $DIR