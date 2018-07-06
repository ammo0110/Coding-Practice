## Journey to the Moon

* Number of possible pairs of astronauts from n astronauts is <sup>n</sup>C<sub>2</sub>
* To find number of pairs where astronauts are from different countries, we need to subtract from <sup>n</sup>C<sub>2</sub>, number of pairs
in which astronauts belong to the same country.
* Using disjoint set data structure, find the number of astronauts belonging to each country. Then for each possible country having number of astronauts
l > 1 is <sup>l</sup>C<sub>2</sub>. Subtract this from <sup>n</sup>C<sub>2</sub>.
