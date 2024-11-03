
# NOTE: May need to run `make` multiple times to get document output!

output_name = reference
input_file = main.tex

all: $(input_file)
	pdflatex -shell-escape -jobname=$(output_name) $(input_file)

clean:
	rm -f *.aux *.log *.toc *.pyg
	rm -rf _minted-main
