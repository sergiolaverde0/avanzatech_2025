DB=enceladus
USER=office
SCRIPTS=${CURDIR}/scripts
PLAN='${CURDIR}/data/master_plan.csv'
BUILD=${CURDIR}/build/build.sql
NORMALIZE=$(SCRIPTS)/normalize.sql
IMPORT=$(SCRIPTS)/import.sql
VIEW=$(SCRIPTS)/views.sql

all: view
	psql -d $(DB) -U $(USER) -f $(BUILD)

schema:
	@cat $(IMPORT) >> $(BUILD)

master: schema
	@printf "\\copy import.master_plan_import \
	FROM $(PLAN) WITH (FORMAT CSV, HEADER); \n" >> $(BUILD)

normalize: master
	@cat $(NORMALIZE) >> $(BUILD)

view: normalize
	@cat $(VIEW) >> $(BUILD)

clean:
	@rm -rf $(BUILD)
