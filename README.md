[![R-CMD-check](https://github.com/wenjie1991/Bc/actions/workflows/check-standard.yaml/badge.svg)](https://github.com/wenjie1991/Bc/actions/workflows/check-standard.yaml)

# Bc

**Bc** is an R package for dealing with **DNA barcoding** sequencing data.

## Kinds of barcodes

**Bc** handle all kinds of DNA barcodes, as long as:

- The barcode have a pattern which be matched by a regular expression.
- Each barcode is within a single sequencing read.

## What you can do with **Bc**

- Performs quality control the DNA sequence results and filters the sequences according
  to the quality metrics.

- Parses sequences, extracts barcode (and UMI) information.

- Performs quality control and filters the barcode.

- Provides toolkits make it easier to manipulate samples and barcodes with metadata.

## Installing

1. Use the `devtools` install package from GitHub

```
library(devtools)
install_github("wenjie1991/Bc")
```

2. Bioconductor
TBD (I hope the package can be accepted in Bioconductor).

## Get start

Here is an example of a basic workflow:

```{r basic_workflow}
library(Bc)
library(magrittr)

# The example data is the mix of MEF lines with known barcodes
# 2000 reads for each file have been sampled for this test dataset
# TODO: Citation of the paper:
example_data <- system.file("extdata", "mef_test_data", package = "Bc")
fq_files <- dir(example_data, "gz", full=TRUE)

# prepare metadata
metadata <- stringr::str_split_fixed(basename(fq_files), "_", 10)[, c(4, 6)]
metadata <- data.frame(metadata)
sample_name <- apply(metadata, 1, paste, collapse = "_")
colnames(metadata) = c("cell_number", "replication")
rownames(metadata) = sample_name
metadata

# extract UMI barcode with regular expression
bc_obj <- bc_extract(
  fq_files,
  pattern = "(.{12})CTCGAGGTCATCGAAGTATCAAG(.+)TAGCAAGCTCGAGAGTAGACCTACT", 
  pattern_type = c("UMI" = 1, "barcode" = 2),
  sample_name = sample_name,
  metadata = metadata
)
bc_obj

# sample subset operation, select technical repeats 'mixa'
bc_sub = bc_obj[, replication == "mixa"]
bc_sub 

# filter the barcode, UMI barcode amplicon > 1 & UMI counts > 1
bc_sub <- bc_cure_umi(bc_sub, depth = 1) %>% bc_cure_depth(depth = 1)

# select barcodes with a white list
bc_sub[c("AAGTCCAGTACTATCGTACTA", "AAGTCCAGTACTGTAGCTACTA"), ]

# export the barcode counts to data.frame
head(bc_2df(bc_sub))

# export the barcode counts to matrix
head(bc_2matrix(bc_sub))
```

## License

[MIT](https://choosealicense.com/licenses/mit/)
