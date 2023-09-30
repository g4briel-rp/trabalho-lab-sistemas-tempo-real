all: vesh

vesh: vesh.c
	gcc vesh.c -o vesh

run: vesh
	./vesh

clean:
	rm vesh
