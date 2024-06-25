.PHONY: clean All

All:
	@echo "----------Building project:[ StatefulLambdas - Debug ]----------"
	@cd "StatefulLambdas" && "$(MAKE)" -f  "StatefulLambdas.mk"
clean:
	@echo "----------Cleaning project:[ StatefulLambdas - Debug ]----------"
	@cd "StatefulLambdas" && "$(MAKE)" -f  "StatefulLambdas.mk" clean
