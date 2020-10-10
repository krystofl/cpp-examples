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






#
# .PHONY: print-tag
# print-tag: ##@Other print the current container image tag
# 	@echo "$(LG_ARROW) Current tag: $(registry)$(app):$(TEXT_GREEN)$(tag)$(TEXT_RESET)"
#
#
#
#
# #############
# ## Release ##
# #############
#
# PHONY: release-build-clean
# release-build-clean: ##@Release Build the release image without cache
# 	@echo "$(LG_ARROW) Building release image without cache $(registry)$(app):$(TEXT_RED):$(tag)-release$(TEXT_RESET)"
# 	docker build --pull --no-cache -t $(registry)$(app):$(tag)-release -f $(dockerfile) --target $(target_name) --build-arg BUILD_TYPE=release .
#
# .PHONY: release-build
# release-build: ##@Release Build the release image
# 	@echo "$(LG_ARROW) Building image $(registry)$(app):$(TEXT_RED)$(tag)-release$(TEXT_RESET)"
# 	docker build -t $(registry)$(app):$(tag)-release -f $(dockerfile) --target $(target_name) --build-arg BUILD_TYPE=release .
#
# .PHONY: release-push
# release-push: release-build ##@Release Build and push the release image
# 	@echo "$(LG_ARROW) Pushing image $(registry)$(app):$(TEXT_RED)$(tag)-release$(TEXT_RESET)"
# 	@docker push $(registry)$(app):$(tag)-release
#
# .PHONY: release-test
# release-test: ##@Release Test the release image
# 	@echo "$(LG_ARROW) Building and running tests on $(app):$(TEXT_RED)$(tag)-release$(TEXT_RESET)"
# 	docker build -t $(registry)$(app):$(tag)-release-tester -f $(dockerfile) --target $(test_target_name) --build-arg BUILD_TYPE=release .
# 	docker run $(registry)$(app):$(tag)-release-tester
#
# .PHONY: release-shell
# release-shell: ##@Release Run the release image locally and open a shell in it
# 	@echo "$(LG_ARROW) Giving you a TTY for $(app):$(TEXT_RED)$(tag)-release$(TEXT_RESET)"
# 	docker run --rm --name $(app) \
# 		--network host \
# 		-it $(registry)$(app):$(tag)-release /bin/bash
#
# .PHONY: release-run
# release-run: ##@Release Run penguin_template_heartbeat in a release container
# 	@echo "$(LG_ARROW) Running penguin_template_heartbeat in $(app):$(TEXT_RED)$(tag)-release$(TEXT_RESET)"
# 	@docker run --rm --name $(app) \
# 		--network host \
# 		-it $(registry)$(app):$(tag)-release
#
#
# ###########
# ## Debug ##
# ###########
#
# PHONY: debug-build-clean
# debug-build-clean: ##@Debug Build the debug image without cache
# 	@echo "$(LG_ARROW) Building debug image without cache $(registry)$(app):$(TEXT_YELLOW):$(tag)-DEBUG$(TEXT_RESET)"
# 	docker build --pull --no-cache -t $(registry)$(app):$(tag)-DEBUG -f $(dockerfile) --target $(target_name) --build-arg BUILD_TYPE=debug .
#
# .PHONY: debug-build
# debug-build: ##@Debug Build the debug image
# 	@echo "$(LG_ARROW) Building image $(registry)$(app):$(TEXT_YELLOW)$(tag)-DEBUG$(TEXT_RESET)"
# 	docker build -t $(registry)$(app):$(tag)-DEBUG -f $(dockerfile) --target $(target_name) --build-arg BUILD_TYPE=debug .
#
# .PHONY: debug-push
# debug-push: debug-build ##@Debug Build and push the debug image
# 	@echo "$(LG_ARROW) Pushing image $(registry)$(app):$(TEXT_YELLOW)$(tag)-DEBUG$(TEXT_RESET)"
# 	@docker push $(registry)$(app):$(tag)-DEBUG
#
# .PHONY: debug-test
# debug-test: ##@Debug Test the debug image
# 	@echo "$(LG_ARROW) Building and running tests on $(app):$(TEXT_YELLOW)$(tag)-DEBUG$(TEXT_RESET)"
# 	docker build -t $(registry)$(app):$(tag)-DEBUG-tester -f $(dockerfile) --target $(test_target_name) --build-arg BUILD_TYPE=debug .
# 	docker run $(registry)$(app):$(tag)-DEBUG-tester
#
# .PHONY: debug-shell
# debug-shell: ##@Debug Run the debug image locally and open a shell in it
# 	@echo "$(LG_ARROW) Giving you a TTY for $(app):$(TEXT_YELLOW)$(tag)-DEBUG$(TEXT_RESET)"
# 	docker run --rm --name $(app) \
# 		--network host \
# 		-it $(registry)$(app):$(tag)-DEBUG /bin/bash
#
# .PHONY: debug-run
# debug-run: ##@Debug Run penguin_template_heartbeat in a debug container
# 	@echo "$(LG_ARROW) Running penguin_template_heartbeat in $(app):$(TEXT_YELLOW)$(tag)-DEBUG$(TEXT_RESET)"
# 	@docker run --rm --name $(app) \
# 		--network host \
# 		-it $(registry)$(app):$(tag)-DEBUG
#
#
# ######################
# ## Bare-Metal Tests ##
# ######################
#
# # .PHONY: baremetal-build
# # baremetal-build: ##@Bare-Metal Build the ROS packages on bare metal.
# # 	colcon build --packages-select cpp_pubsub penguin_template
# #
# # .PHONY: baremetal-run-heartbeat
# # baremetal-run-heartbeat: ##@Bare-Metal Run the heartbeat on bare metal
# # 	@source ./install/setup.bash; ros2 run penguin_template heartbeat
# #
# # .PHONY: baremetal-run-penguin-demo
# # baremetal-run-penguin-demo: ##@Bare-Metal Run the heartbeat on bare metal
# # 	./install/penguin_template/lib/penguin_template/penguin_demo
