#load necessary libraries 
library(dplyr)
set.seed(123)
months<-c("jan","feb","mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec")
revenue<-round(runif(12,min=800,max=1200),2)*1000
expenses<-round(runif(12,min=600,max=1000),2)*1000
profit<-revenue-expenses
tax_rate<-0.30
profit_after_tax<-profit*(1-tax_rate)
profit_margin<-(profit_after_tax/revenue)*100
mean_profit_after_tax<-mean(profit_after_tax)
good_months<-months[profit_after_tax>mean_profit_after_tax]
bad_months<-months[profit_after_tax<mean_profit_after_tax]
best_months<-months[which.max(profit_after_tax)]
worst_months<-months[which.min(profit_after_tax)]
profit<-format(profit/1000,nsmall=2)
profit_after_tax<-format(profit_after_tax/1000,nsmall=0)
results<-data.frame(
  Months=months,
  Profit=paste("$",profit),
  profit_after_tax=paste("$",profit_after_tax),
  profit_margin=paste(profit_margin,"%"),
  good_months=paste(good_months,collapse = ","),
  bad_months=paste(bad_months,collapse = ","),
  best_months=best_months,
  worst_months=worst_months
)
write.csv(results,file = "D:/financial_metrics_results.csv",row.names = FALSE)
print(results)
  
  