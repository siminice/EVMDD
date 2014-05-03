#!/bin/csh

set m = 100

foreach d (1 2 3 4 5)
  foreach n  (100 200 300 400 500 600 700 800 900 1000)
    foreach x (1 2 3 4 5)
      @ m = ( $n * $x )
      foreach r (0 1 2 3 4 5 6 7 8 9)
        echo 'Running instance with n='$n', m='$m', d='$d', r#'$r'...'
        timeout -9 1800 ./quickgen $n $m $d $r
      end
    end
  end
end
