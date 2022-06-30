// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// seq_correct
List seq_correct(std::vector<std::string> seq, IntegerVector count, int count_threshold, int dist_threshold, double depth_fold_threshold, int dist_method, int insert_cost, int delete_cost, int replace_cost);
RcppExport SEXP _CellBarcode_seq_correct(SEXP seqSEXP, SEXP countSEXP, SEXP count_thresholdSEXP, SEXP dist_thresholdSEXP, SEXP depth_fold_thresholdSEXP, SEXP dist_methodSEXP, SEXP insert_costSEXP, SEXP delete_costSEXP, SEXP replace_costSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::string> >::type seq(seqSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type count(countSEXP);
    Rcpp::traits::input_parameter< int >::type count_threshold(count_thresholdSEXP);
    Rcpp::traits::input_parameter< int >::type dist_threshold(dist_thresholdSEXP);
    Rcpp::traits::input_parameter< double >::type depth_fold_threshold(depth_fold_thresholdSEXP);
    Rcpp::traits::input_parameter< int >::type dist_method(dist_methodSEXP);
    Rcpp::traits::input_parameter< int >::type insert_cost(insert_costSEXP);
    Rcpp::traits::input_parameter< int >::type delete_cost(delete_costSEXP);
    Rcpp::traits::input_parameter< int >::type replace_cost(replace_costSEXP);
    rcpp_result_gen = Rcpp::wrap(seq_correct(seq, count, count_threshold, dist_threshold, depth_fold_threshold, dist_method, insert_cost, delete_cost, replace_cost));
    return rcpp_result_gen;
END_RCPP
}
// read_fastq_gz
DataFrame read_fastq_gz(std::string in_file_path);
RcppExport SEXP _CellBarcode_read_fastq_gz(SEXP in_file_pathSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type in_file_path(in_file_pathSEXP);
    rcpp_result_gen = Rcpp::wrap(read_fastq_gz(in_file_path));
    return rcpp_result_gen;
END_RCPP
}
// read_fastq
DataFrame read_fastq(std::string in_file_path);
RcppExport SEXP _CellBarcode_read_fastq(SEXP in_file_pathSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type in_file_path(in_file_pathSEXP);
    rcpp_result_gen = Rcpp::wrap(read_fastq(in_file_path));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_CellBarcode_seq_correct", (DL_FUNC) &_CellBarcode_seq_correct, 9},
    {"_CellBarcode_read_fastq_gz", (DL_FUNC) &_CellBarcode_read_fastq_gz, 1},
    {"_CellBarcode_read_fastq", (DL_FUNC) &_CellBarcode_read_fastq, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_CellBarcode(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
