# ft_cpp

CPP modules + all their subject

## PDF

- [CPP_00](./PDF/CPP00.en.subject.pdf)
- [CPP_01](./PDF/CPP01.en.subject.pdf)
- [CPP_02](./PDF/CPP02.en.subject.pdf)
- [CPP_03](./PDF/CPP03.en.subject.pdf)
- [CPP_04](./PDF/CPP04.en.subject.pdf)
- [CPP_05](./PDF/CPP05.en.subject.pdf)
- [CPP_06](./PDF/CPP06.en.subject.pdf)
- [CPP_07](./PDF/CPP07.en.subject.pdf)
- [CPP_08](./PDF/CPP08.en.subject.pdf)
- [CPP_09](./PDF/CPP09.en.subject.pdf)

## USEFULL COMMAND

> clean all modules
```bash
for file in $(find . -type f ! -path "./TEMPLATE/*" -name "Makefile" -print | sort); do
	make -sC "${file%\/*}" fclean
done
```
