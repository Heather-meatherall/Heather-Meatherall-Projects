Comparing DnD Stats
================
Heather Meatherall - 100823999
2025-04-02

Dungeons and Dragons (DnD) is one of the most popular Tabletop Role
Playing Games (TTRPG). As someone who’s main DnD group spans 3 different
countries, I wanted to see how its popularity varied by country. To do
this, I went to Google Trends and downloaded [search term
data](https://trends.google.com/trends/explore?q=dungeons%20and%20dragons&date=today%205-y)
from the past 5 years, including low search volume regions. Google
determines popularity by dividing the number times a certain term is
searched for, in this case “dungeons and dragons”, by the total number
of overall searches.

Looking at this map, we can see that DnD’s popularity is highest in
places like Canada, Australia, and the United States. It’s important to
note that since this data is based on an English search term, the
results will be skewed towards countries with a higher volume of English
speakers.

``` r
dnd_popularity <- read_csv("geoMap.csv", show_col_types = FALSE)

#Code to rename entries to match world data set taken from https://sarahpenir.github.io/r/making-maps/
dnd_popularity <- dnd_popularity %>%
  mutate(Country = recode(str_trim(Country), "United States" = "USA", "United Kingdom" = "UK" ))


world <- map_data("world")

world_map <- left_join(world, dnd_popularity, join_by(region == Country))

mapPlot <- ggplot(world_map, aes(x = long, y = lat, group = group)) +
  geom_polygon(aes(fill = `dungeons and dragons: (3/27/20 - 3/27/25)` ), color = "white")+
  scale_fill_viridis_c(option = "F", direction = -1) +
  theme_map() +
  theme(legend.position = "right") +
  labs(fill="Relative Popularity Percentage", title = "Dungeons and Dragons Searches From 3/27/20 to 3/27/25") +
  coord_quickmap()


plot(mapPlot)
```

![](heather-meatherall-project_files/figure-gfm/unnamed-chunk-1-1.png)<!-- -->

Next, I turned to data from the actual game. The monster manual is
filled with variety of different creatures you can fight, from everyday
animals to the terrifying Tarasque. In this report, I wanted to see if
there were any interesting relationships between the stats, with a
particular focus on whether or not size had any impact on them.

``` r
d <- read_csv("Dd5e_monsters.csv", show_col_types = FALSE)

#tidyr tidying
#Separate 'Race + alignment' column into two separate ones
d <- separate_wider_delim(d, cols='Race + alignment', delim=",", names = c("Race", "Alignment"), cols_remove = TRUE, too_many = "merge", too_few = "align_start")

#Separate 'Armor' column into two separate columns
d <- separate_wider_delim(d, cols='Armor', delim=" ", names = c("AC", "Armour Type"), cols_remove = TRUE, too_many = "merge", too_few = "align_start")

#Separate 'Challenge rating  (XP)' column into two separate columns
d <- separate_wider_delim(d, cols='Challenge rating  (XP)', delim=" ", names = c("Challenge Rating", "XP"), cols_remove = TRUE, too_many = "merge")

#Make numerical 
d$AC <- as.numeric(d$AC)
d$`Challenge Rating` <- as.numeric(d$`Challenge Rating`)

#Drop NA values
d <- as_tibble(d) |>
  filter(!is.na(AC)) |>
  filter(!is.na(`Challenge Rating`))
```

First, I made a pie chart that showed the proportions of the different
sizes a monster could be. The pie chart revealed that medium and large
are the most common sizes, which means that during an average DnD game,
a player can expect to encounter a medium or large sized monster more
often.

``` r
d_size_Subset <- d %>% group_by(Size) %>%
  summarise(total_count=n())

#order largest to smallest
d_pie <- mutate(d_size_Subset, Size = fct_reorder(Size, total_count )) %>%
  mutate(d_size_Subset, perc = total_count / sum(total_count))

#get postioning for labels
d_pie <- d_pie %>%
  mutate(csum = rev(cumsum(rev(total_count))), 
         pos = total_count/2 + lead(csum, 1),
         pos = if_else(is.na(pos), total_count/2, pos))

piePlot <- ggplot(d_pie, aes(x="", y=total_count, fill=Size))  +
  geom_bar(stat="identity", width=1, colour="white") +
  coord_polar("y", start=0) +
  scale_fill_brewer(palette = "PuRd") +
  theme_void() +
  geom_label_repel(data = d_pie,
                   aes(y = pos, label = paste0(total_count, "%")),
                   size = 4.5, nudge_x = 1, show.legend = FALSE) +
  labs(title="Proportion of Different Monster Sizes in DnD 5e")

plot(piePlot)
```

![](heather-meatherall-project_files/figure-gfm/unnamed-chunk-3-1.png)<!-- -->

Turning to this report’s main question, I started by looking at a
monster’s Challenge Rating. Challenge Rating is the approximation of how
difficult a monster will be to fight. Generally, the higher the
Challenge Rating the harder a fight with this monster will be.

In the below bar chart we can see that larger monsters have a higher
Challenge Rating. We can also see that gargantuan monsters are the only
size with an average Challenge Rating greater than 15.

``` r
d_challenge_sub <- filter(d, !is.na(`Challenge Rating`))
d_challenge_sub <- d_challenge_sub %>%
  group_by(Size) %>%
  summarise(`Challenge Rating` = mean(`Challenge Rating`))

d_challenge_sub <- mutate(d_challenge_sub, is_bigger = if_else(`Challenge Rating` > 15, "Yes", "No"))

barPlot <- ggplot(d_challenge_sub, aes(x = Size, y = `Challenge Rating`, fill=is_bigger)) + 
  geom_bar(stat='identity') +
  labs(title="Average Challenge Ratings By Size", y="Average Challenge Rating", fill="Challenge Rating > 15") +
  scale_fill_brewer(palette = "Accent" ) +
  theme_clean()

plot(barPlot)
```

![](heather-meatherall-project_files/figure-gfm/unnamed-chunk-4-1.png)<!-- -->

The next stat I looked at was Armour Class (AC). AC represents how a
monster will be to hit. For example, if a monster has an AC of 10,
during a fight a player needs to roll a 10 or higher to hit the monster.
The higher the AC the harder a monster will be to hit.

I created a violin chart to show the distribution of AC of each size,
sorted by median value. In this visualization, we can see that the
average AC goes up as the size does.

``` r
#sorts size groups by median
d_violin <- mutate(d, Size = fct_reorder(Size, AC, .fun='median' ))

violinPlot <- ggplot(d_violin, aes(x=Size, y=AC)) +
  geom_violin(fill = "pink", colour="#d4426f", trim=FALSE) +
  geom_boxplot(width=0.1, colour="#bf00ff", alpha=0.2) +
  labs(title="AC Density of Monster Sizes") +
  theme_minimal()

plot(violinPlot)
```

![](heather-meatherall-project_files/figure-gfm/unnamed-chunk-5-1.png)<!-- -->

After looking at the two visualizations above, I was curious to see if
AC and Challenge Rating had any relation. After plotting the information
in a scatter plot, it revealed that as Challenge Rating went up, so did
AC.

``` r
# scatter plot of AC vs Challenge rating, groups of sizes

scatterPlot <- ggplot(d, aes(x=`Challenge Rating`, y=AC)) +
  geom_smooth(method="lm", formula = 'y~x', colour="darkgrey") +
  geom_point(aes(colour=d$Size), size=3) +
  scale_x_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  scale_y_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  scale_color_brewer(palette = "Dark2") +
  labs(title = " AC vs Challenge Rating of Dnd Monsters", colour="Size") +
  theme_igray()

plot(scatterPlot)
```

![](heather-meatherall-project_files/figure-gfm/unnamed-chunk-6-1.png)<!-- -->

While the above scatter plot is coloured by size, I also graphed each
size on separately, which allows us to see the trends between sizes
better. Here we can see that large and medium sized monsters have more
variety in their stats, while the other sizes follow their general
patterns more closely.

``` r
p1 <- ggplot(subset(d, Size %in% "Gargantuan"), aes(x=`Challenge Rating`, y=AC)) +
  geom_smooth(method="lm", formula = 'y~x', colour="darkgrey") +
  geom_point(colour = "#1b9e77", size = 3) +
  scale_x_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  scale_y_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  labs(title = " AC vs Challenge Rating of Gargantuan Dnd Monsters")

p2 <- ggplot(subset(d, Size %in% "Huge"), aes(x=`Challenge Rating`, y=AC)) +
  geom_smooth(method="lm", formula = 'y~x', colour="darkgrey") +
  geom_point(colour = "#d95f02", size = 3) +
  scale_x_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  scale_y_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  labs(title = " AC vs Challenge Rating of Huge Dnd Monsters")

p3 <- ggplot(subset(d, Size %in% "Large"), aes(x=`Challenge Rating`, y=AC)) +
  geom_smooth(method="lm", formula = 'y~x', colour="darkgrey") +
  geom_point(colour = "#7570b3", size = 3) +
  scale_x_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  scale_y_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  labs(title = " AC vs Challenge Rating of Large Dnd Monsters")

p4 <- ggplot(subset(d, Size %in% "Medium"), aes(x=`Challenge Rating`, y=AC)) +
  geom_smooth(method="lm", formula = 'y~x', colour="darkgrey") +
  geom_point(colour = "#e7298a", size = 3) +
  scale_x_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  scale_y_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  labs(title = " AC vs Challenge Rating of Medium Dnd Monsters")

p5 <- ggplot(subset(d, Size %in% "Small"), aes(x=`Challenge Rating`, y=AC)) +
  geom_smooth(method="lm", formula = 'y~x', colour="darkgrey") +
  geom_point(colour = "#66a61e", size = 3) +
  scale_x_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  scale_y_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  labs(title = " AC vs Challenge Rating of Small Dnd Monsters")

p6 <- ggplot(subset(d, Size %in% "Tiny"), aes(x=`Challenge Rating`, y=AC)) +
  geom_smooth(method="lm", formula = 'y~x', colour="darkgrey") +
  geom_point(colour = "#e6ab02", size = 3) +
  scale_x_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  scale_y_continuous(limits = c(0,30), breaks = pretty(0:30)) +
  labs(title = " AC vs Challenge Rating of Tiny Dnd Monsters")

(p1 + p2 + p3) / (p4 + p5 + p6)
```

![](heather-meatherall-project_files/figure-gfm/unnamed-chunk-7-1.png)<!-- -->

Looking at the various visualizations in this report, we can see that
size does have an impact on a monster’s stats. As the size increases so
does the various stats, meaning that a fight with a larger monster will
most likely be harder than a fight with a smaller one As well, Challenge
Rating and AC are related to one other, as one value increases so does
the other. This means that a DnD player can safely assume that a monster
with a high Challenge Rating will have a high AC.

## Dataset Links

Map data taken from Google Trends on March 26 at 8:30pm
<https://trends.google.com/trends/explore?q=dungeons%20and%20dragons&date=today%205-y>

Dnd Monster dataset taken from Kaggle
<https://www.kaggle.com/datasets/mrpantherson/dnd-5e-monsters>
