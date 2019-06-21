TEMPLATE = subdirs

SUBDIRS += library
SUBDIRS += test

test.depends = library
