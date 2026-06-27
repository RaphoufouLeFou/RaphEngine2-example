cmake -B build
cmake --build build
if [ $? -eq 0 ] ; then
    mv build/RaphEngine2_example RaphEngine2_example
fi

./RaphEngine2_example
