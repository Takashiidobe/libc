PANDOC ?= pandoc

SOURCE_DOCS := $(shell find docs -type f -name "*.md")

HTML_FILES=$(SOURCE_DOCS:%.md=html/%.html) 
MAN_FILES=$(SOURCE_DOCS:%.md=man/%.man) 
# PDF_FILES=$(SOURCE_DOCS:%.md=pdf/%.pdf) 

EXPORTED_DOCS=$(HTML_FILES) $(MAN_FILES) # $(PDF_FILES)

RM=/bin/rm

PANDOC_OPTIONS=--standalone

PANDOC_HTML_OPTIONS=--to html5 --template=./_template.html
PANDOC_MAN_OPTIONS=--to man
PANDOC_PDF_OPTIONS=--to pdf

# Pattern-matching Rules
html/%.html: %.md
	mkdir -p $(dir $@)
	$(PANDOC) $(PANDOC_OPTIONS) $(PANDOC_HTML_OPTIONS) -o $@ $<
	sed -i 's/\.md/\.html/g' $@

man/%.man: %.md 
	mkdir -p $(dir $@)
	$(PANDOC) $(PANDOC_OPTIONS) $(PANDOC_MAN_OPTIONS) -o $@ $<
	sed -i 's/\.md/.man/g' $@

# pdf/%.pdf: %.md 
# 	mkdir -p $(dir $@)
# 	$(PANDOC) $(PANDOC_OPTIONS) $(PANDOC_PDF_OPTIONS) -o $@ $<
# 	sed -i 's/\.md/.pdf/g' $@

.PHONY: docs docs_clean
docs: $(EXPORTED_DOCS)
	./bin/iterate 

docs_clean:
	- $(RM) $(EXPORTED_DOCS)

CC = clang
CFLAGS = -Wall -Werror

LIBS = $(shell find lib/ -type f -name "*.c")
TEST_FILES = $(shell find test/ -type f -name "*.h")

.PHONY: test test_clean
test: 
	$(CC) $(CFLAGS) $(LIBS) test/tests.c $< -o test/out/tests 

test_clean:
	- $(RM) test/out/tests

define HELP_TEXT
make                  generates docs for libc project (html and man)
make html/index.html  generate docs for just index.html
make docs_clean       deletes doc dir
make test             runs tests for project	
make test_clean       deletes assets created by running tests for libc project
endef

export HELP_TEXT

help:
	@echo "$$HELP_TEXT"
