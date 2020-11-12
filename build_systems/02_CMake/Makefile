# Command Runner
# The actual program uses CMake for building; see README.md for more info

SHELL := /bin/bash

DEBUG_DIR   := build-debug
RELEASE_DIR := build-release

# Text colors
TEXT_BOLD   := $(shell tput -Txterm bold)
TEXT_RED    := $(shell tput -Txterm setaf 1)
TEXT_GREEN  := $(shell tput -Txterm setaf 2)
TEXT_WHITE  := $(shell tput -Txterm setaf 7)
TEXT_YELLOW := $(shell tput -Txterm setaf 3)
TEXT_RESET  := $(shell tput -Txterm sgr0)

LG_ARROW := $(TEXT_BOLD)$(TEXT_GREEN)==>$(TEXT_RESET)
ARROW := $(TEXT_YELLOW)->$(TEXT_RESET)

# And add help text after each target name starting with ##
# A category can be added with @category
HELP_FUN = \
	%help; \
	while(<>) { push @{$$help{$$2 // 'options'}}, [$$1, $$3] if /^([a-zA-Z\-]+)\s*:.*\#\#(?:@([a-zA-Z\-]+))?\s(.*)$$/ }; \
	print "usage: make [target] (option=value)\n\n"; \
	for (sort keys %help) { \
	print "${TEXT_WHITE}$$_:${TEXT_RESET}\n"; \
	for (@{$$help{$$_}}) { \
	$$sep = " " x (24 - length $$_->[0]); \
	print "  ${TEXT_YELLOW}$$_->[0]${TEXT_RESET}$$sep${TEXT_GREEN}$$_->[1]${TEXT_RESET}\n"; \
	}; \
	print "\n"; }

help: ##@Other Show this help
	@perl -e '$(HELP_FUN)' $(MAKEFILE_LIST)


install-libs: ##@Other Install needed libraries under ./libs
	cd libs && ./install_libs.sh


# =========================== DEBUG build targets ==============================

debug-cmake: ##@Debug Use CMake to generate Makefiles for the DEBUG build
	cd $(DEBUG_DIR) && cmake -DCMAKE_BUILD_TYPE=Debug ..

debug: ##@Debug Build the Debug version
	$(MAKE) -C $(DEBUG_DIR)

debug-test: debug ##@Debug Run the debug testbench
	cd $(DEBUG_DIR) && ./run_person_tests

debug-clean: ##@Debug Clean all debug build files
	rm -r $(DEBUG_DIR)/*


# =========================== RELEASE build targets ============================

release-cmake: ##@Release Use CMake to generate Makefiles for the release build
	cd $(RELEASE_DIR) && cmake -DCMAKE_BUILD_TYPE=Release ..

release: ##@Release Build the release version
	$(MAKE) -C $(RELEASE_DIR)

release-test: release ##@Release Run the release testbench
	cd $(RELEASE_DIR) && ./run_person_tests

release-clean: ##@Release Clean all debug build files
	rm -r $(RELEASE_DIR)/*
