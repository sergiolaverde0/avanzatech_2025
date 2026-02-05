DB=enceladus
USER=office
SCRIPTS=${CURDIR}/scripts
PLAN='${CURDIR}/data/master_plan.csv'
CDA='${CURDIR}/data/CDA/cda.csv'
FLYBYS='${CURDIR}/data/jpl_flybys.csv'
CHEM='${CURDIR}/data/INMS/chem_data.csv'
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
	FROM $(PLAN) WITH (FORMAT CSV, HEADER);\n\
	\\copy import.cda_import \
	FROM $(CDA) WITH (FORMAT CSV, HEADER);\n\
	\\copy flybys \
	FROM $(FLYBYS) WITH (FORMAT CSV, HEADER)\n\
	\\copy chem_data \
	FROM $(CHEM) WITH (FORMAT CSV, HEADER)\n" >> $(BUILD)

normalize: master
	@cat $(NORMALIZE) >> $(BUILD)

view: normalize
	@cat $(VIEW) >> $(BUILD)

clean:
	@rm -rf $(BUILD)
