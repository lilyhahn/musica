#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR
cd src
g++ -I/Users/thahn/utils/homebrew/include -L/Users/thahn/utils/homebrew/lib/ -I/Users/thahn/utils/irrKlang/include -L/Users/thahn/utils/irrKlang/bin/macosx-gcc -I/Users/thahn/codestuff/camusic/include -lgd -lirrklang -std=c++0x -arch i386  *.cpp -o /Users/thahn/codestuff/camusic/bin/rule30
cd ../bin
install_name_tool -change /Users/thahn/utils/homebrew/lib/libgd.3.dylib ./lib/libgd.dylib rule30
install_name_tool -change /usr/local/lib/libirrklang.dylib ./lib/libirrklang.dylib rule30