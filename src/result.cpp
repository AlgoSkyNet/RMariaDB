#include <Rcpp.h>
#include "RMariaDB_types.h"
using namespace Rcpp;

// [[Rcpp::export]]
XPtr<MyResult> result_create(XPtr<MyConnectionPtr> con, std::string sql) {
  std::auto_ptr<MyResult> res(new MyResult(*con));
  res->sendQuery(sql);
  return XPtr<MyResult>(res.release(), true);
}

// [[Rcpp::export]]
List result_column_info(XPtr<MyResult> rs) {
  return rs->columnInfo();
}

// [[Rcpp::export]]
List result_fetch(XPtr<MyResult> rs, int n) {
  return rs->fetch(n);
}

// [[Rcpp::export]]
void result_bind(XPtr<MyResult> rs, List params) {
  return rs->bind(params);
}

// [[Rcpp::export]]
void result_bind_rows(XPtr<MyResult> rs, List params) {
  return rs->bindRows(params);
}

// [[Rcpp::export]]
void result_release(XPtr<MyResult> rs) {
  rs.release();
}

// [[Rcpp::export]]
int result_rows_affected(XPtr<MyResult> rs) {
  return rs->rowsAffected();
}

// [[Rcpp::export]]
int result_rows_fetched(XPtr<MyResult> rs) {
  return rs->rowsFetched();
}

// [[Rcpp::export]]
bool result_complete(XPtr<MyResult> rs) {
  return rs->complete();
}

// [[Rcpp::export]]
bool result_active(XPtr<MyResult> rs) {
  return rs.get() != NULL &&  rs->active();
}
