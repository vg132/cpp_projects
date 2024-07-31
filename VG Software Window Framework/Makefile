all: build-framework build-test

clean:
	make -C framework clean
	make -C testapp clean

build-framework:
	make -C framework all

build-test:
	make -C testapp all

run:
	./testapp/bin/test

leak:
	LeakTracer/LeakCheck /home/viktor/dev/dsv/cpp/windowtest/bin/test

debug:
	gdb ./testapp/bin/test
