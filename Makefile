SUBDIR = src

define make_subdir
	@for subdir in $(SUBDIR); do \
	(cd $$subdir && make $1) \
	done;
endef

all:
	$(call make_subdir, all)
	
clean:
	$(call make_subdir, clean)
	
install:
	$(call make_subdir, install)