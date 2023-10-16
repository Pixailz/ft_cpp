# ft_cpp

CPP modules + all their subject

|Project|Grade|PDF|
|:-:|:-:|:-:|
|||
|CPP00|![](https://img.shields.io/static/v1?logo=42&label=&message=80&color=brightgreen)|[CPP_00](./PDF/CPP00.en.subject.pdf)|
|CPP01|![](https://img.shields.io/static/v1?logo=42&label=&message=100&color=yellow)|[CPP_01](./PDF/CPP01.en.subject.pdf)|
|CPP02|![](https://img.shields.io/static/v1?logo=42&label=&message=80&color=brightgreen)|[CPP_02](./PDF/CPP02.en.subject.pdf)|
|CPP03|![](https://img.shields.io/static/v1?logo=42&label=&message=80&color=brightgreen)|[CPP_03](./PDF/CPP03.en.subject.pdf)|
|CPP04|![](https://img.shields.io/static/v1?logo=42&label=&message=80&color=brightgreen)|[CPP_04](./PDF/CPP04.en.subject.pdf)|
|||
|CPP05|![](https://img.shields.io/static/v1?logo=42&label=&message=100&color=yellow)|[CPP_05](./PDF/CPP05.en.subject.pdf)|
|CPP06|![](https://img.shields.io/static/v1?logo=42&label=&message=100&color=yellow)|[CPP_06](./PDF/CPP06.en.subject.pdf)|
|CPP07|![](https://img.shields.io/static/v1?logo=42&label=&message=80&color=brightgreen)|[CPP_07](./PDF/CPP07.en.subject.pdf)|
|CPP08|![](https://img.shields.io/static/v1?logo=42&label=&message=100&color=yellow)|[CPP_08](./PDF/CPP08.en.subject.pdf)|
|CPP09|![](https://img.shields.io/static/v1?logo=42&label=&message=100&color=yellow)|[CPP_09](./PDF/CPP09.en.subject.pdf)|
|||

## USEFULL COMMAND

> clean all modules
```bash
for file in $(find . -type f ! -path "./TEMPLATE/*" -name "Makefile" -print | sort); do
	make -sC "${file%\/*}" fclean
done
```
