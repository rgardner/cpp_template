test: clean
    cookiecutter . -o output --overwrite-if-exists --no-input
    just output/awesome_cpp/ci

clean:
    rm -rf output
