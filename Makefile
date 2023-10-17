all: lib app

lib:
    @echo "Building the static library..."
    $(MAKE) -C lib -f Makefile_lib

app:
    @echo "Building the application..."
    $(MAKE) -f Makefile_app

clean:
    $(MAKE) -C lib -f Makefile_lib clean
    $(MAKE) -f Makefile_app clean
