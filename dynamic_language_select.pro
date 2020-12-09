TEMPLATE = subdirs

SUBDIRS += \
	translatable_qml \
	translatable_widget \
	translator

translatable_qml.depends += translator
translatable_widget.depends += translator
