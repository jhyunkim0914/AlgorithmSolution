1. 실행법
실행하고자 하는 폴더 선택 후 Run 돌리면 됨

(cd ${selected.file.path} && ${c.cpp.set.compiler} $(find ${selected.file.path} -name *.cpp -o -name *.c) -o ${selected.file.path}/result.out ${c.cpp.set.build.options} -lm && ${selected.file.path}/result.out)