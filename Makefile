.PHONY: clean All

All:
	@echo "----------Building project:[ FunctionObjects - Debug ]----------"
	@cd "FunctionObjects" && "$(MAKE)" -f  "FunctionObjects.mk"
clean:
	@echo "----------Cleaning project:[ FunctionObjects - Debug ]----------"
	@cd "FunctionObjects" && "$(MAKE)" -f  "FunctionObjects.mk" clean
