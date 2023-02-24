clean:
	rm -rf *.exe

%: %.c
	cc $< -o $@.exe
	./$@.exe
	rm $@.exe