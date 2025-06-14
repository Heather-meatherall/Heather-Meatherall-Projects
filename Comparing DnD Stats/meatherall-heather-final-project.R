setwd('C:/csci1030/Documents/InfoVis/project')

graphics.off()
rm(list=ls())
library(tidyverse)
library(dplyr)

d <- read_csv("Dd5e_monsters.csv")

#tidyr tidyingd
d <- separate_wider_delim(d, cols='Race + alignment', delim=",", names = c("Race", "Alignment"), cols_remove = TRUE, too_many = "merge")

#TODO: get values out of brackets
d <- separate_wider_delim(d, cols='Armor', delim=" ", names = c("Armour", "Type"), cols_remove = TRUE, too_many = "merge", too_few = "align_start")

d <- separate_wider_delim(d, cols='Challenge rating  (XP)', delim=" ", names = c("Challenge Rating", "XP"), cols_remove = TRUE, too_many = "merge")


d$

# TODO
# pie graph showing different sizes
# scatter plot alignment
# violin plot about species / dragons
# geographic map (xp??)
# armour type vs hp?

#Size Pie Chart
dSubset <- d$Size

dSubset <- table(dSubset)
dSubset <- dSubset/sum(dSubset)
dSubset <- as.data.frame(dSubset)

piePlot <- ggplot(dSubset, aes(x="", y=Freq, fill=dSubset)) +
  geom_bar(stat="identity", width=1, colour="white") +
  coord_polar("y", start=0) +
  theme_void() +
  labs(title="Proportion of Different Sizes of Dnd Monsters")

# 
barPlot <- ggplot(d, aes(Size, fill=Alignment)) + geom_bar(position = "stack") + labs(title="Types of Dd5e Monsters, Coloured by Size")

