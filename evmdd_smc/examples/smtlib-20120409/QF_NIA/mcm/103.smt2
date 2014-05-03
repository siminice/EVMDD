(set-logic QF_NIA)
(set-info :source |
 more info in 'N. P. Lopes, L. Aksoy, V. Manquinho, J. Monteiro.
 Optimally Solving the MCM Problem Using Pseudo-Boolean Satisfiability.
 Technical Report RT/43/2010, INESC-ID, Nov. 2010'. |)
(declare-fun X0 () Int)
(declare-fun X1 () Int)
(declare-fun X2 () Int)
(declare-fun X3 () Int)
(declare-fun X4 () Int)
(declare-fun X5 () Int)
(declare-fun X6 () Int)
(declare-fun X7 () Int)
(declare-fun X8 () Int)
(declare-fun X9 () Int)
(declare-fun X10 () Int)
(declare-fun X11 () Int)
(declare-fun S0 () Int)
(declare-fun S1 () Int)
(declare-fun S2 () Int)
(declare-fun S3 () Int)
(declare-fun S4 () Int)
(declare-fun S5 () Int)
(declare-fun S6 () Int)
(declare-fun S7 () Int)
(declare-fun S8 () Int)
(declare-fun S9 () Int)
(declare-fun S10 () Int)
(declare-fun S11 () Int)
(declare-fun S12 () Int)
(declare-fun S13 () Int)
(declare-fun S14 () Int)
(declare-fun S15 () Int)
(declare-fun S16 () Int)
(declare-fun S17 () Int)
(declare-fun S18 () Int)
(declare-fun S19 () Int)
(declare-fun S20 () Int)
(declare-fun S21 () Int)
(declare-fun S22 () Int)
(declare-fun S23 () Int)
(define-fun power2 ((x Int)) Bool
  (or (= x 2048) (= x 1024) (= x 512) (= x 256) (= x 128) (= x 64) (= x 32) (= x 16) (= x 8) (= x 4) (= x 2) (= x 1)))
(assert (or
 (= X0 (+ S0 S1))
 (= X0 (- S0 S1))
))
(assert (and (> X0 0) (< X0 4096) (power2 S0) (power2 S1)))
(assert (or
 (= X1 (+ S2 S3))
 (= X1 (- S2 S3))
 (= X1 (+ (* X0 S2) S3))
 (= X1 (- (* X0 S2) S3))
 (= X1 (- S2 (* X0 S3)))
 (= X1 (+ (* X0 S2) (* X0 S3)))
 (= X1 (- (* X0 S2) (* X0 S3)))
))
(assert (and (> X1 0) (< X1 4096) (power2 S2) (power2 S3)))
(assert (or
 (= X2 (+ (* X0 S4) S5))
 (= X2 (- (* X0 S4) S5))
 (= X2 (- S4 (* X0 S5)))
 (= X2 (+ (* X0 S4) (* X0 S5)))
 (= X2 (- (* X0 S4) (* X0 S5)))
 (= X2 (+ (* X0 S4) (* X1 S5)))
 (= X2 (- (* X0 S4) (* X1 S5)))
 (= X2 (- (* X1 S4) (* X0 S5)))
 (= X2 (+ (* X1 S4) S5))
 (= X2 (- (* X1 S4) S5))
 (= X2 (- S4 (* X1 S5)))
 (= X2 (+ (* X1 S4) (* X1 S5)))
 (= X2 (- (* X1 S4) (* X1 S5)))
))
(assert (and (> X2 0) (< X2 4096) (power2 S4) (power2 S5)))
(assert (or
 (= X3 (+ (* X0 S6) S7))
 (= X3 (- (* X0 S6) S7))
 (= X3 (- S6 (* X0 S7)))
 (= X3 (+ (* X0 S6) (* X0 S7)))
 (= X3 (- (* X0 S6) (* X0 S7)))
 (= X3 (+ (* X0 S6) (* X1 S7)))
 (= X3 (- (* X0 S6) (* X1 S7)))
 (= X3 (- (* X1 S6) (* X0 S7)))
 (= X3 (+ (* X0 S6) (* X2 S7)))
 (= X3 (- (* X0 S6) (* X2 S7)))
 (= X3 (- (* X2 S6) (* X0 S7)))
 (= X3 (+ (* X1 S6) S7))
 (= X3 (- (* X1 S6) S7))
 (= X3 (- S6 (* X1 S7)))
 (= X3 (+ (* X1 S6) (* X1 S7)))
 (= X3 (- (* X1 S6) (* X1 S7)))
 (= X3 (+ (* X1 S6) (* X2 S7)))
 (= X3 (- (* X1 S6) (* X2 S7)))
 (= X3 (- (* X2 S6) (* X1 S7)))
 (= X3 (+ (* X2 S6) S7))
 (= X3 (- (* X2 S6) S7))
 (= X3 (- S6 (* X2 S7)))
 (= X3 (+ (* X2 S6) (* X2 S7)))
 (= X3 (- (* X2 S6) (* X2 S7)))
))
(assert (and (> X3 0) (< X3 4096) (power2 S6) (power2 S7)))
(assert (or
 (= X4 (+ (* X0 S8) S9))
 (= X4 (- (* X0 S8) S9))
 (= X4 (- S8 (* X0 S9)))
 (= X4 (+ (* X0 S8) (* X0 S9)))
 (= X4 (- (* X0 S8) (* X0 S9)))
 (= X4 (+ (* X0 S8) (* X1 S9)))
 (= X4 (- (* X0 S8) (* X1 S9)))
 (= X4 (- (* X1 S8) (* X0 S9)))
 (= X4 (+ (* X0 S8) (* X2 S9)))
 (= X4 (- (* X0 S8) (* X2 S9)))
 (= X4 (- (* X2 S8) (* X0 S9)))
 (= X4 (+ (* X0 S8) (* X3 S9)))
 (= X4 (- (* X0 S8) (* X3 S9)))
 (= X4 (- (* X3 S8) (* X0 S9)))
 (= X4 (+ (* X1 S8) S9))
 (= X4 (- (* X1 S8) S9))
 (= X4 (- S8 (* X1 S9)))
 (= X4 (+ (* X1 S8) (* X1 S9)))
 (= X4 (- (* X1 S8) (* X1 S9)))
 (= X4 (+ (* X1 S8) (* X2 S9)))
 (= X4 (- (* X1 S8) (* X2 S9)))
 (= X4 (- (* X2 S8) (* X1 S9)))
 (= X4 (+ (* X1 S8) (* X3 S9)))
 (= X4 (- (* X1 S8) (* X3 S9)))
 (= X4 (- (* X3 S8) (* X1 S9)))
 (= X4 (+ (* X2 S8) S9))
 (= X4 (- (* X2 S8) S9))
 (= X4 (- S8 (* X2 S9)))
 (= X4 (+ (* X2 S8) (* X2 S9)))
 (= X4 (- (* X2 S8) (* X2 S9)))
 (= X4 (+ (* X2 S8) (* X3 S9)))
 (= X4 (- (* X2 S8) (* X3 S9)))
 (= X4 (- (* X3 S8) (* X2 S9)))
 (= X4 (+ (* X3 S8) S9))
 (= X4 (- (* X3 S8) S9))
 (= X4 (- S8 (* X3 S9)))
 (= X4 (+ (* X3 S8) (* X3 S9)))
 (= X4 (- (* X3 S8) (* X3 S9)))
))
(assert (and (> X4 0) (< X4 4096) (power2 S8) (power2 S9)))
(assert (or
 (= X5 (+ (* X0 S10) S11))
 (= X5 (- (* X0 S10) S11))
 (= X5 (- S10 (* X0 S11)))
 (= X5 (+ (* X0 S10) (* X0 S11)))
 (= X5 (- (* X0 S10) (* X0 S11)))
 (= X5 (+ (* X0 S10) (* X1 S11)))
 (= X5 (- (* X0 S10) (* X1 S11)))
 (= X5 (- (* X1 S10) (* X0 S11)))
 (= X5 (+ (* X0 S10) (* X2 S11)))
 (= X5 (- (* X0 S10) (* X2 S11)))
 (= X5 (- (* X2 S10) (* X0 S11)))
 (= X5 (+ (* X0 S10) (* X3 S11)))
 (= X5 (- (* X0 S10) (* X3 S11)))
 (= X5 (- (* X3 S10) (* X0 S11)))
 (= X5 (+ (* X0 S10) (* X4 S11)))
 (= X5 (- (* X0 S10) (* X4 S11)))
 (= X5 (- (* X4 S10) (* X0 S11)))
 (= X5 (+ (* X1 S10) S11))
 (= X5 (- (* X1 S10) S11))
 (= X5 (- S10 (* X1 S11)))
 (= X5 (+ (* X1 S10) (* X1 S11)))
 (= X5 (- (* X1 S10) (* X1 S11)))
 (= X5 (+ (* X1 S10) (* X2 S11)))
 (= X5 (- (* X1 S10) (* X2 S11)))
 (= X5 (- (* X2 S10) (* X1 S11)))
 (= X5 (+ (* X1 S10) (* X3 S11)))
 (= X5 (- (* X1 S10) (* X3 S11)))
 (= X5 (- (* X3 S10) (* X1 S11)))
 (= X5 (+ (* X1 S10) (* X4 S11)))
 (= X5 (- (* X1 S10) (* X4 S11)))
 (= X5 (- (* X4 S10) (* X1 S11)))
 (= X5 (+ (* X2 S10) S11))
 (= X5 (- (* X2 S10) S11))
 (= X5 (- S10 (* X2 S11)))
 (= X5 (+ (* X2 S10) (* X2 S11)))
 (= X5 (- (* X2 S10) (* X2 S11)))
 (= X5 (+ (* X2 S10) (* X3 S11)))
 (= X5 (- (* X2 S10) (* X3 S11)))
 (= X5 (- (* X3 S10) (* X2 S11)))
 (= X5 (+ (* X2 S10) (* X4 S11)))
 (= X5 (- (* X2 S10) (* X4 S11)))
 (= X5 (- (* X4 S10) (* X2 S11)))
 (= X5 (+ (* X3 S10) S11))
 (= X5 (- (* X3 S10) S11))
 (= X5 (- S10 (* X3 S11)))
 (= X5 (+ (* X3 S10) (* X3 S11)))
 (= X5 (- (* X3 S10) (* X3 S11)))
 (= X5 (+ (* X3 S10) (* X4 S11)))
 (= X5 (- (* X3 S10) (* X4 S11)))
 (= X5 (- (* X4 S10) (* X3 S11)))
 (= X5 (+ (* X4 S10) S11))
 (= X5 (- (* X4 S10) S11))
 (= X5 (- S10 (* X4 S11)))
 (= X5 (+ (* X4 S10) (* X4 S11)))
 (= X5 (- (* X4 S10) (* X4 S11)))
))
(assert (and (> X5 0) (< X5 4096) (power2 S10) (power2 S11)))
(assert (or
 (= X6 (+ (* X0 S12) S13))
 (= X6 (- (* X0 S12) S13))
 (= X6 (- S12 (* X0 S13)))
 (= X6 (+ (* X0 S12) (* X0 S13)))
 (= X6 (- (* X0 S12) (* X0 S13)))
 (= X6 (+ (* X0 S12) (* X1 S13)))
 (= X6 (- (* X0 S12) (* X1 S13)))
 (= X6 (- (* X1 S12) (* X0 S13)))
 (= X6 (+ (* X0 S12) (* X2 S13)))
 (= X6 (- (* X0 S12) (* X2 S13)))
 (= X6 (- (* X2 S12) (* X0 S13)))
 (= X6 (+ (* X0 S12) (* X3 S13)))
 (= X6 (- (* X0 S12) (* X3 S13)))
 (= X6 (- (* X3 S12) (* X0 S13)))
 (= X6 (+ (* X0 S12) (* X4 S13)))
 (= X6 (- (* X0 S12) (* X4 S13)))
 (= X6 (- (* X4 S12) (* X0 S13)))
 (= X6 (+ (* X0 S12) (* X5 S13)))
 (= X6 (- (* X0 S12) (* X5 S13)))
 (= X6 (- (* X5 S12) (* X0 S13)))
 (= X6 (+ (* X1 S12) S13))
 (= X6 (- (* X1 S12) S13))
 (= X6 (- S12 (* X1 S13)))
 (= X6 (+ (* X1 S12) (* X1 S13)))
 (= X6 (- (* X1 S12) (* X1 S13)))
 (= X6 (+ (* X1 S12) (* X2 S13)))
 (= X6 (- (* X1 S12) (* X2 S13)))
 (= X6 (- (* X2 S12) (* X1 S13)))
 (= X6 (+ (* X1 S12) (* X3 S13)))
 (= X6 (- (* X1 S12) (* X3 S13)))
 (= X6 (- (* X3 S12) (* X1 S13)))
 (= X6 (+ (* X1 S12) (* X4 S13)))
 (= X6 (- (* X1 S12) (* X4 S13)))
 (= X6 (- (* X4 S12) (* X1 S13)))
 (= X6 (+ (* X1 S12) (* X5 S13)))
 (= X6 (- (* X1 S12) (* X5 S13)))
 (= X6 (- (* X5 S12) (* X1 S13)))
 (= X6 (+ (* X2 S12) S13))
 (= X6 (- (* X2 S12) S13))
 (= X6 (- S12 (* X2 S13)))
 (= X6 (+ (* X2 S12) (* X2 S13)))
 (= X6 (- (* X2 S12) (* X2 S13)))
 (= X6 (+ (* X2 S12) (* X3 S13)))
 (= X6 (- (* X2 S12) (* X3 S13)))
 (= X6 (- (* X3 S12) (* X2 S13)))
 (= X6 (+ (* X2 S12) (* X4 S13)))
 (= X6 (- (* X2 S12) (* X4 S13)))
 (= X6 (- (* X4 S12) (* X2 S13)))
 (= X6 (+ (* X2 S12) (* X5 S13)))
 (= X6 (- (* X2 S12) (* X5 S13)))
 (= X6 (- (* X5 S12) (* X2 S13)))
 (= X6 (+ (* X3 S12) S13))
 (= X6 (- (* X3 S12) S13))
 (= X6 (- S12 (* X3 S13)))
 (= X6 (+ (* X3 S12) (* X3 S13)))
 (= X6 (- (* X3 S12) (* X3 S13)))
 (= X6 (+ (* X3 S12) (* X4 S13)))
 (= X6 (- (* X3 S12) (* X4 S13)))
 (= X6 (- (* X4 S12) (* X3 S13)))
 (= X6 (+ (* X3 S12) (* X5 S13)))
 (= X6 (- (* X3 S12) (* X5 S13)))
 (= X6 (- (* X5 S12) (* X3 S13)))
 (= X6 (+ (* X4 S12) S13))
 (= X6 (- (* X4 S12) S13))
 (= X6 (- S12 (* X4 S13)))
 (= X6 (+ (* X4 S12) (* X4 S13)))
 (= X6 (- (* X4 S12) (* X4 S13)))
 (= X6 (+ (* X4 S12) (* X5 S13)))
 (= X6 (- (* X4 S12) (* X5 S13)))
 (= X6 (- (* X5 S12) (* X4 S13)))
 (= X6 (+ (* X5 S12) S13))
 (= X6 (- (* X5 S12) S13))
 (= X6 (- S12 (* X5 S13)))
 (= X6 (+ (* X5 S12) (* X5 S13)))
 (= X6 (- (* X5 S12) (* X5 S13)))
))
(assert (and (> X6 0) (< X6 4096) (power2 S12) (power2 S13)))
(assert (or
 (= X7 (+ (* X0 S14) S15))
 (= X7 (- (* X0 S14) S15))
 (= X7 (- S14 (* X0 S15)))
 (= X7 (+ (* X0 S14) (* X0 S15)))
 (= X7 (- (* X0 S14) (* X0 S15)))
 (= X7 (+ (* X0 S14) (* X1 S15)))
 (= X7 (- (* X0 S14) (* X1 S15)))
 (= X7 (- (* X1 S14) (* X0 S15)))
 (= X7 (+ (* X0 S14) (* X2 S15)))
 (= X7 (- (* X0 S14) (* X2 S15)))
 (= X7 (- (* X2 S14) (* X0 S15)))
 (= X7 (+ (* X0 S14) (* X3 S15)))
 (= X7 (- (* X0 S14) (* X3 S15)))
 (= X7 (- (* X3 S14) (* X0 S15)))
 (= X7 (+ (* X0 S14) (* X4 S15)))
 (= X7 (- (* X0 S14) (* X4 S15)))
 (= X7 (- (* X4 S14) (* X0 S15)))
 (= X7 (+ (* X0 S14) (* X5 S15)))
 (= X7 (- (* X0 S14) (* X5 S15)))
 (= X7 (- (* X5 S14) (* X0 S15)))
 (= X7 (+ (* X0 S14) (* X6 S15)))
 (= X7 (- (* X0 S14) (* X6 S15)))
 (= X7 (- (* X6 S14) (* X0 S15)))
 (= X7 (+ (* X1 S14) S15))
 (= X7 (- (* X1 S14) S15))
 (= X7 (- S14 (* X1 S15)))
 (= X7 (+ (* X1 S14) (* X1 S15)))
 (= X7 (- (* X1 S14) (* X1 S15)))
 (= X7 (+ (* X1 S14) (* X2 S15)))
 (= X7 (- (* X1 S14) (* X2 S15)))
 (= X7 (- (* X2 S14) (* X1 S15)))
 (= X7 (+ (* X1 S14) (* X3 S15)))
 (= X7 (- (* X1 S14) (* X3 S15)))
 (= X7 (- (* X3 S14) (* X1 S15)))
 (= X7 (+ (* X1 S14) (* X4 S15)))
 (= X7 (- (* X1 S14) (* X4 S15)))
 (= X7 (- (* X4 S14) (* X1 S15)))
 (= X7 (+ (* X1 S14) (* X5 S15)))
 (= X7 (- (* X1 S14) (* X5 S15)))
 (= X7 (- (* X5 S14) (* X1 S15)))
 (= X7 (+ (* X1 S14) (* X6 S15)))
 (= X7 (- (* X1 S14) (* X6 S15)))
 (= X7 (- (* X6 S14) (* X1 S15)))
 (= X7 (+ (* X2 S14) S15))
 (= X7 (- (* X2 S14) S15))
 (= X7 (- S14 (* X2 S15)))
 (= X7 (+ (* X2 S14) (* X2 S15)))
 (= X7 (- (* X2 S14) (* X2 S15)))
 (= X7 (+ (* X2 S14) (* X3 S15)))
 (= X7 (- (* X2 S14) (* X3 S15)))
 (= X7 (- (* X3 S14) (* X2 S15)))
 (= X7 (+ (* X2 S14) (* X4 S15)))
 (= X7 (- (* X2 S14) (* X4 S15)))
 (= X7 (- (* X4 S14) (* X2 S15)))
 (= X7 (+ (* X2 S14) (* X5 S15)))
 (= X7 (- (* X2 S14) (* X5 S15)))
 (= X7 (- (* X5 S14) (* X2 S15)))
 (= X7 (+ (* X2 S14) (* X6 S15)))
 (= X7 (- (* X2 S14) (* X6 S15)))
 (= X7 (- (* X6 S14) (* X2 S15)))
 (= X7 (+ (* X3 S14) S15))
 (= X7 (- (* X3 S14) S15))
 (= X7 (- S14 (* X3 S15)))
 (= X7 (+ (* X3 S14) (* X3 S15)))
 (= X7 (- (* X3 S14) (* X3 S15)))
 (= X7 (+ (* X3 S14) (* X4 S15)))
 (= X7 (- (* X3 S14) (* X4 S15)))
 (= X7 (- (* X4 S14) (* X3 S15)))
 (= X7 (+ (* X3 S14) (* X5 S15)))
 (= X7 (- (* X3 S14) (* X5 S15)))
 (= X7 (- (* X5 S14) (* X3 S15)))
 (= X7 (+ (* X3 S14) (* X6 S15)))
 (= X7 (- (* X3 S14) (* X6 S15)))
 (= X7 (- (* X6 S14) (* X3 S15)))
 (= X7 (+ (* X4 S14) S15))
 (= X7 (- (* X4 S14) S15))
 (= X7 (- S14 (* X4 S15)))
 (= X7 (+ (* X4 S14) (* X4 S15)))
 (= X7 (- (* X4 S14) (* X4 S15)))
 (= X7 (+ (* X4 S14) (* X5 S15)))
 (= X7 (- (* X4 S14) (* X5 S15)))
 (= X7 (- (* X5 S14) (* X4 S15)))
 (= X7 (+ (* X4 S14) (* X6 S15)))
 (= X7 (- (* X4 S14) (* X6 S15)))
 (= X7 (- (* X6 S14) (* X4 S15)))
 (= X7 (+ (* X5 S14) S15))
 (= X7 (- (* X5 S14) S15))
 (= X7 (- S14 (* X5 S15)))
 (= X7 (+ (* X5 S14) (* X5 S15)))
 (= X7 (- (* X5 S14) (* X5 S15)))
 (= X7 (+ (* X5 S14) (* X6 S15)))
 (= X7 (- (* X5 S14) (* X6 S15)))
 (= X7 (- (* X6 S14) (* X5 S15)))
 (= X7 (+ (* X6 S14) S15))
 (= X7 (- (* X6 S14) S15))
 (= X7 (- S14 (* X6 S15)))
 (= X7 (+ (* X6 S14) (* X6 S15)))
 (= X7 (- (* X6 S14) (* X6 S15)))
))
(assert (and (> X7 0) (< X7 4096) (power2 S14) (power2 S15)))
(assert (or
 (= X8 (+ (* X0 S16) S17))
 (= X8 (- (* X0 S16) S17))
 (= X8 (- S16 (* X0 S17)))
 (= X8 (+ (* X0 S16) (* X0 S17)))
 (= X8 (- (* X0 S16) (* X0 S17)))
 (= X8 (+ (* X0 S16) (* X1 S17)))
 (= X8 (- (* X0 S16) (* X1 S17)))
 (= X8 (- (* X1 S16) (* X0 S17)))
 (= X8 (+ (* X0 S16) (* X2 S17)))
 (= X8 (- (* X0 S16) (* X2 S17)))
 (= X8 (- (* X2 S16) (* X0 S17)))
 (= X8 (+ (* X0 S16) (* X3 S17)))
 (= X8 (- (* X0 S16) (* X3 S17)))
 (= X8 (- (* X3 S16) (* X0 S17)))
 (= X8 (+ (* X0 S16) (* X4 S17)))
 (= X8 (- (* X0 S16) (* X4 S17)))
 (= X8 (- (* X4 S16) (* X0 S17)))
 (= X8 (+ (* X0 S16) (* X5 S17)))
 (= X8 (- (* X0 S16) (* X5 S17)))
 (= X8 (- (* X5 S16) (* X0 S17)))
 (= X8 (+ (* X0 S16) (* X6 S17)))
 (= X8 (- (* X0 S16) (* X6 S17)))
 (= X8 (- (* X6 S16) (* X0 S17)))
 (= X8 (+ (* X0 S16) (* X7 S17)))
 (= X8 (- (* X0 S16) (* X7 S17)))
 (= X8 (- (* X7 S16) (* X0 S17)))
 (= X8 (+ (* X1 S16) S17))
 (= X8 (- (* X1 S16) S17))
 (= X8 (- S16 (* X1 S17)))
 (= X8 (+ (* X1 S16) (* X1 S17)))
 (= X8 (- (* X1 S16) (* X1 S17)))
 (= X8 (+ (* X1 S16) (* X2 S17)))
 (= X8 (- (* X1 S16) (* X2 S17)))
 (= X8 (- (* X2 S16) (* X1 S17)))
 (= X8 (+ (* X1 S16) (* X3 S17)))
 (= X8 (- (* X1 S16) (* X3 S17)))
 (= X8 (- (* X3 S16) (* X1 S17)))
 (= X8 (+ (* X1 S16) (* X4 S17)))
 (= X8 (- (* X1 S16) (* X4 S17)))
 (= X8 (- (* X4 S16) (* X1 S17)))
 (= X8 (+ (* X1 S16) (* X5 S17)))
 (= X8 (- (* X1 S16) (* X5 S17)))
 (= X8 (- (* X5 S16) (* X1 S17)))
 (= X8 (+ (* X1 S16) (* X6 S17)))
 (= X8 (- (* X1 S16) (* X6 S17)))
 (= X8 (- (* X6 S16) (* X1 S17)))
 (= X8 (+ (* X1 S16) (* X7 S17)))
 (= X8 (- (* X1 S16) (* X7 S17)))
 (= X8 (- (* X7 S16) (* X1 S17)))
 (= X8 (+ (* X2 S16) S17))
 (= X8 (- (* X2 S16) S17))
 (= X8 (- S16 (* X2 S17)))
 (= X8 (+ (* X2 S16) (* X2 S17)))
 (= X8 (- (* X2 S16) (* X2 S17)))
 (= X8 (+ (* X2 S16) (* X3 S17)))
 (= X8 (- (* X2 S16) (* X3 S17)))
 (= X8 (- (* X3 S16) (* X2 S17)))
 (= X8 (+ (* X2 S16) (* X4 S17)))
 (= X8 (- (* X2 S16) (* X4 S17)))
 (= X8 (- (* X4 S16) (* X2 S17)))
 (= X8 (+ (* X2 S16) (* X5 S17)))
 (= X8 (- (* X2 S16) (* X5 S17)))
 (= X8 (- (* X5 S16) (* X2 S17)))
 (= X8 (+ (* X2 S16) (* X6 S17)))
 (= X8 (- (* X2 S16) (* X6 S17)))
 (= X8 (- (* X6 S16) (* X2 S17)))
 (= X8 (+ (* X2 S16) (* X7 S17)))
 (= X8 (- (* X2 S16) (* X7 S17)))
 (= X8 (- (* X7 S16) (* X2 S17)))
 (= X8 (+ (* X3 S16) S17))
 (= X8 (- (* X3 S16) S17))
 (= X8 (- S16 (* X3 S17)))
 (= X8 (+ (* X3 S16) (* X3 S17)))
 (= X8 (- (* X3 S16) (* X3 S17)))
 (= X8 (+ (* X3 S16) (* X4 S17)))
 (= X8 (- (* X3 S16) (* X4 S17)))
 (= X8 (- (* X4 S16) (* X3 S17)))
 (= X8 (+ (* X3 S16) (* X5 S17)))
 (= X8 (- (* X3 S16) (* X5 S17)))
 (= X8 (- (* X5 S16) (* X3 S17)))
 (= X8 (+ (* X3 S16) (* X6 S17)))
 (= X8 (- (* X3 S16) (* X6 S17)))
 (= X8 (- (* X6 S16) (* X3 S17)))
 (= X8 (+ (* X3 S16) (* X7 S17)))
 (= X8 (- (* X3 S16) (* X7 S17)))
 (= X8 (- (* X7 S16) (* X3 S17)))
 (= X8 (+ (* X4 S16) S17))
 (= X8 (- (* X4 S16) S17))
 (= X8 (- S16 (* X4 S17)))
 (= X8 (+ (* X4 S16) (* X4 S17)))
 (= X8 (- (* X4 S16) (* X4 S17)))
 (= X8 (+ (* X4 S16) (* X5 S17)))
 (= X8 (- (* X4 S16) (* X5 S17)))
 (= X8 (- (* X5 S16) (* X4 S17)))
 (= X8 (+ (* X4 S16) (* X6 S17)))
 (= X8 (- (* X4 S16) (* X6 S17)))
 (= X8 (- (* X6 S16) (* X4 S17)))
 (= X8 (+ (* X4 S16) (* X7 S17)))
 (= X8 (- (* X4 S16) (* X7 S17)))
 (= X8 (- (* X7 S16) (* X4 S17)))
 (= X8 (+ (* X5 S16) S17))
 (= X8 (- (* X5 S16) S17))
 (= X8 (- S16 (* X5 S17)))
 (= X8 (+ (* X5 S16) (* X5 S17)))
 (= X8 (- (* X5 S16) (* X5 S17)))
 (= X8 (+ (* X5 S16) (* X6 S17)))
 (= X8 (- (* X5 S16) (* X6 S17)))
 (= X8 (- (* X6 S16) (* X5 S17)))
 (= X8 (+ (* X5 S16) (* X7 S17)))
 (= X8 (- (* X5 S16) (* X7 S17)))
 (= X8 (- (* X7 S16) (* X5 S17)))
 (= X8 (+ (* X6 S16) S17))
 (= X8 (- (* X6 S16) S17))
 (= X8 (- S16 (* X6 S17)))
 (= X8 (+ (* X6 S16) (* X6 S17)))
 (= X8 (- (* X6 S16) (* X6 S17)))
 (= X8 (+ (* X6 S16) (* X7 S17)))
 (= X8 (- (* X6 S16) (* X7 S17)))
 (= X8 (- (* X7 S16) (* X6 S17)))
 (= X8 (+ (* X7 S16) S17))
 (= X8 (- (* X7 S16) S17))
 (= X8 (- S16 (* X7 S17)))
 (= X8 (+ (* X7 S16) (* X7 S17)))
 (= X8 (- (* X7 S16) (* X7 S17)))
))
(assert (and (> X8 0) (< X8 4096) (power2 S16) (power2 S17)))
(assert (or
 (= X9 (+ (* X0 S18) S19))
 (= X9 (- (* X0 S18) S19))
 (= X9 (- S18 (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X0 S19)))
 (= X9 (- (* X0 S18) (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X1 S19)))
 (= X9 (- (* X0 S18) (* X1 S19)))
 (= X9 (- (* X1 S18) (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X2 S19)))
 (= X9 (- (* X0 S18) (* X2 S19)))
 (= X9 (- (* X2 S18) (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X3 S19)))
 (= X9 (- (* X0 S18) (* X3 S19)))
 (= X9 (- (* X3 S18) (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X4 S19)))
 (= X9 (- (* X0 S18) (* X4 S19)))
 (= X9 (- (* X4 S18) (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X5 S19)))
 (= X9 (- (* X0 S18) (* X5 S19)))
 (= X9 (- (* X5 S18) (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X6 S19)))
 (= X9 (- (* X0 S18) (* X6 S19)))
 (= X9 (- (* X6 S18) (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X7 S19)))
 (= X9 (- (* X0 S18) (* X7 S19)))
 (= X9 (- (* X7 S18) (* X0 S19)))
 (= X9 (+ (* X0 S18) (* X8 S19)))
 (= X9 (- (* X0 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X0 S19)))
 (= X9 (+ (* X1 S18) S19))
 (= X9 (- (* X1 S18) S19))
 (= X9 (- S18 (* X1 S19)))
 (= X9 (+ (* X1 S18) (* X1 S19)))
 (= X9 (- (* X1 S18) (* X1 S19)))
 (= X9 (+ (* X1 S18) (* X2 S19)))
 (= X9 (- (* X1 S18) (* X2 S19)))
 (= X9 (- (* X2 S18) (* X1 S19)))
 (= X9 (+ (* X1 S18) (* X3 S19)))
 (= X9 (- (* X1 S18) (* X3 S19)))
 (= X9 (- (* X3 S18) (* X1 S19)))
 (= X9 (+ (* X1 S18) (* X4 S19)))
 (= X9 (- (* X1 S18) (* X4 S19)))
 (= X9 (- (* X4 S18) (* X1 S19)))
 (= X9 (+ (* X1 S18) (* X5 S19)))
 (= X9 (- (* X1 S18) (* X5 S19)))
 (= X9 (- (* X5 S18) (* X1 S19)))
 (= X9 (+ (* X1 S18) (* X6 S19)))
 (= X9 (- (* X1 S18) (* X6 S19)))
 (= X9 (- (* X6 S18) (* X1 S19)))
 (= X9 (+ (* X1 S18) (* X7 S19)))
 (= X9 (- (* X1 S18) (* X7 S19)))
 (= X9 (- (* X7 S18) (* X1 S19)))
 (= X9 (+ (* X1 S18) (* X8 S19)))
 (= X9 (- (* X1 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X1 S19)))
 (= X9 (+ (* X2 S18) S19))
 (= X9 (- (* X2 S18) S19))
 (= X9 (- S18 (* X2 S19)))
 (= X9 (+ (* X2 S18) (* X2 S19)))
 (= X9 (- (* X2 S18) (* X2 S19)))
 (= X9 (+ (* X2 S18) (* X3 S19)))
 (= X9 (- (* X2 S18) (* X3 S19)))
 (= X9 (- (* X3 S18) (* X2 S19)))
 (= X9 (+ (* X2 S18) (* X4 S19)))
 (= X9 (- (* X2 S18) (* X4 S19)))
 (= X9 (- (* X4 S18) (* X2 S19)))
 (= X9 (+ (* X2 S18) (* X5 S19)))
 (= X9 (- (* X2 S18) (* X5 S19)))
 (= X9 (- (* X5 S18) (* X2 S19)))
 (= X9 (+ (* X2 S18) (* X6 S19)))
 (= X9 (- (* X2 S18) (* X6 S19)))
 (= X9 (- (* X6 S18) (* X2 S19)))
 (= X9 (+ (* X2 S18) (* X7 S19)))
 (= X9 (- (* X2 S18) (* X7 S19)))
 (= X9 (- (* X7 S18) (* X2 S19)))
 (= X9 (+ (* X2 S18) (* X8 S19)))
 (= X9 (- (* X2 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X2 S19)))
 (= X9 (+ (* X3 S18) S19))
 (= X9 (- (* X3 S18) S19))
 (= X9 (- S18 (* X3 S19)))
 (= X9 (+ (* X3 S18) (* X3 S19)))
 (= X9 (- (* X3 S18) (* X3 S19)))
 (= X9 (+ (* X3 S18) (* X4 S19)))
 (= X9 (- (* X3 S18) (* X4 S19)))
 (= X9 (- (* X4 S18) (* X3 S19)))
 (= X9 (+ (* X3 S18) (* X5 S19)))
 (= X9 (- (* X3 S18) (* X5 S19)))
 (= X9 (- (* X5 S18) (* X3 S19)))
 (= X9 (+ (* X3 S18) (* X6 S19)))
 (= X9 (- (* X3 S18) (* X6 S19)))
 (= X9 (- (* X6 S18) (* X3 S19)))
 (= X9 (+ (* X3 S18) (* X7 S19)))
 (= X9 (- (* X3 S18) (* X7 S19)))
 (= X9 (- (* X7 S18) (* X3 S19)))
 (= X9 (+ (* X3 S18) (* X8 S19)))
 (= X9 (- (* X3 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X3 S19)))
 (= X9 (+ (* X4 S18) S19))
 (= X9 (- (* X4 S18) S19))
 (= X9 (- S18 (* X4 S19)))
 (= X9 (+ (* X4 S18) (* X4 S19)))
 (= X9 (- (* X4 S18) (* X4 S19)))
 (= X9 (+ (* X4 S18) (* X5 S19)))
 (= X9 (- (* X4 S18) (* X5 S19)))
 (= X9 (- (* X5 S18) (* X4 S19)))
 (= X9 (+ (* X4 S18) (* X6 S19)))
 (= X9 (- (* X4 S18) (* X6 S19)))
 (= X9 (- (* X6 S18) (* X4 S19)))
 (= X9 (+ (* X4 S18) (* X7 S19)))
 (= X9 (- (* X4 S18) (* X7 S19)))
 (= X9 (- (* X7 S18) (* X4 S19)))
 (= X9 (+ (* X4 S18) (* X8 S19)))
 (= X9 (- (* X4 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X4 S19)))
 (= X9 (+ (* X5 S18) S19))
 (= X9 (- (* X5 S18) S19))
 (= X9 (- S18 (* X5 S19)))
 (= X9 (+ (* X5 S18) (* X5 S19)))
 (= X9 (- (* X5 S18) (* X5 S19)))
 (= X9 (+ (* X5 S18) (* X6 S19)))
 (= X9 (- (* X5 S18) (* X6 S19)))
 (= X9 (- (* X6 S18) (* X5 S19)))
 (= X9 (+ (* X5 S18) (* X7 S19)))
 (= X9 (- (* X5 S18) (* X7 S19)))
 (= X9 (- (* X7 S18) (* X5 S19)))
 (= X9 (+ (* X5 S18) (* X8 S19)))
 (= X9 (- (* X5 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X5 S19)))
 (= X9 (+ (* X6 S18) S19))
 (= X9 (- (* X6 S18) S19))
 (= X9 (- S18 (* X6 S19)))
 (= X9 (+ (* X6 S18) (* X6 S19)))
 (= X9 (- (* X6 S18) (* X6 S19)))
 (= X9 (+ (* X6 S18) (* X7 S19)))
 (= X9 (- (* X6 S18) (* X7 S19)))
 (= X9 (- (* X7 S18) (* X6 S19)))
 (= X9 (+ (* X6 S18) (* X8 S19)))
 (= X9 (- (* X6 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X6 S19)))
 (= X9 (+ (* X7 S18) S19))
 (= X9 (- (* X7 S18) S19))
 (= X9 (- S18 (* X7 S19)))
 (= X9 (+ (* X7 S18) (* X7 S19)))
 (= X9 (- (* X7 S18) (* X7 S19)))
 (= X9 (+ (* X7 S18) (* X8 S19)))
 (= X9 (- (* X7 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X7 S19)))
 (= X9 (+ (* X8 S18) S19))
 (= X9 (- (* X8 S18) S19))
 (= X9 (- S18 (* X8 S19)))
 (= X9 (+ (* X8 S18) (* X8 S19)))
 (= X9 (- (* X8 S18) (* X8 S19)))
))
(assert (and (> X9 0) (< X9 4096) (power2 S18) (power2 S19)))
(assert (or
 (= X10 (+ (* X0 S20) S21))
 (= X10 (- (* X0 S20) S21))
 (= X10 (- S20 (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X0 S21)))
 (= X10 (- (* X0 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X1 S21)))
 (= X10 (- (* X0 S20) (* X1 S21)))
 (= X10 (- (* X1 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X2 S21)))
 (= X10 (- (* X0 S20) (* X2 S21)))
 (= X10 (- (* X2 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X3 S21)))
 (= X10 (- (* X0 S20) (* X3 S21)))
 (= X10 (- (* X3 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X4 S21)))
 (= X10 (- (* X0 S20) (* X4 S21)))
 (= X10 (- (* X4 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X5 S21)))
 (= X10 (- (* X0 S20) (* X5 S21)))
 (= X10 (- (* X5 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X6 S21)))
 (= X10 (- (* X0 S20) (* X6 S21)))
 (= X10 (- (* X6 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X7 S21)))
 (= X10 (- (* X0 S20) (* X7 S21)))
 (= X10 (- (* X7 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X8 S21)))
 (= X10 (- (* X0 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X0 S21)))
 (= X10 (+ (* X0 S20) (* X9 S21)))
 (= X10 (- (* X0 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X0 S21)))
 (= X10 (+ (* X1 S20) S21))
 (= X10 (- (* X1 S20) S21))
 (= X10 (- S20 (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X1 S21)))
 (= X10 (- (* X1 S20) (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X2 S21)))
 (= X10 (- (* X1 S20) (* X2 S21)))
 (= X10 (- (* X2 S20) (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X3 S21)))
 (= X10 (- (* X1 S20) (* X3 S21)))
 (= X10 (- (* X3 S20) (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X4 S21)))
 (= X10 (- (* X1 S20) (* X4 S21)))
 (= X10 (- (* X4 S20) (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X5 S21)))
 (= X10 (- (* X1 S20) (* X5 S21)))
 (= X10 (- (* X5 S20) (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X6 S21)))
 (= X10 (- (* X1 S20) (* X6 S21)))
 (= X10 (- (* X6 S20) (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X7 S21)))
 (= X10 (- (* X1 S20) (* X7 S21)))
 (= X10 (- (* X7 S20) (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X8 S21)))
 (= X10 (- (* X1 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X1 S21)))
 (= X10 (+ (* X1 S20) (* X9 S21)))
 (= X10 (- (* X1 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X1 S21)))
 (= X10 (+ (* X2 S20) S21))
 (= X10 (- (* X2 S20) S21))
 (= X10 (- S20 (* X2 S21)))
 (= X10 (+ (* X2 S20) (* X2 S21)))
 (= X10 (- (* X2 S20) (* X2 S21)))
 (= X10 (+ (* X2 S20) (* X3 S21)))
 (= X10 (- (* X2 S20) (* X3 S21)))
 (= X10 (- (* X3 S20) (* X2 S21)))
 (= X10 (+ (* X2 S20) (* X4 S21)))
 (= X10 (- (* X2 S20) (* X4 S21)))
 (= X10 (- (* X4 S20) (* X2 S21)))
 (= X10 (+ (* X2 S20) (* X5 S21)))
 (= X10 (- (* X2 S20) (* X5 S21)))
 (= X10 (- (* X5 S20) (* X2 S21)))
 (= X10 (+ (* X2 S20) (* X6 S21)))
 (= X10 (- (* X2 S20) (* X6 S21)))
 (= X10 (- (* X6 S20) (* X2 S21)))
 (= X10 (+ (* X2 S20) (* X7 S21)))
 (= X10 (- (* X2 S20) (* X7 S21)))
 (= X10 (- (* X7 S20) (* X2 S21)))
 (= X10 (+ (* X2 S20) (* X8 S21)))
 (= X10 (- (* X2 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X2 S21)))
 (= X10 (+ (* X2 S20) (* X9 S21)))
 (= X10 (- (* X2 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X2 S21)))
 (= X10 (+ (* X3 S20) S21))
 (= X10 (- (* X3 S20) S21))
 (= X10 (- S20 (* X3 S21)))
 (= X10 (+ (* X3 S20) (* X3 S21)))
 (= X10 (- (* X3 S20) (* X3 S21)))
 (= X10 (+ (* X3 S20) (* X4 S21)))
 (= X10 (- (* X3 S20) (* X4 S21)))
 (= X10 (- (* X4 S20) (* X3 S21)))
 (= X10 (+ (* X3 S20) (* X5 S21)))
 (= X10 (- (* X3 S20) (* X5 S21)))
 (= X10 (- (* X5 S20) (* X3 S21)))
 (= X10 (+ (* X3 S20) (* X6 S21)))
 (= X10 (- (* X3 S20) (* X6 S21)))
 (= X10 (- (* X6 S20) (* X3 S21)))
 (= X10 (+ (* X3 S20) (* X7 S21)))
 (= X10 (- (* X3 S20) (* X7 S21)))
 (= X10 (- (* X7 S20) (* X3 S21)))
 (= X10 (+ (* X3 S20) (* X8 S21)))
 (= X10 (- (* X3 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X3 S21)))
 (= X10 (+ (* X3 S20) (* X9 S21)))
 (= X10 (- (* X3 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X3 S21)))
 (= X10 (+ (* X4 S20) S21))
 (= X10 (- (* X4 S20) S21))
 (= X10 (- S20 (* X4 S21)))
 (= X10 (+ (* X4 S20) (* X4 S21)))
 (= X10 (- (* X4 S20) (* X4 S21)))
 (= X10 (+ (* X4 S20) (* X5 S21)))
 (= X10 (- (* X4 S20) (* X5 S21)))
 (= X10 (- (* X5 S20) (* X4 S21)))
 (= X10 (+ (* X4 S20) (* X6 S21)))
 (= X10 (- (* X4 S20) (* X6 S21)))
 (= X10 (- (* X6 S20) (* X4 S21)))
 (= X10 (+ (* X4 S20) (* X7 S21)))
 (= X10 (- (* X4 S20) (* X7 S21)))
 (= X10 (- (* X7 S20) (* X4 S21)))
 (= X10 (+ (* X4 S20) (* X8 S21)))
 (= X10 (- (* X4 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X4 S21)))
 (= X10 (+ (* X4 S20) (* X9 S21)))
 (= X10 (- (* X4 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X4 S21)))
 (= X10 (+ (* X5 S20) S21))
 (= X10 (- (* X5 S20) S21))
 (= X10 (- S20 (* X5 S21)))
 (= X10 (+ (* X5 S20) (* X5 S21)))
 (= X10 (- (* X5 S20) (* X5 S21)))
 (= X10 (+ (* X5 S20) (* X6 S21)))
 (= X10 (- (* X5 S20) (* X6 S21)))
 (= X10 (- (* X6 S20) (* X5 S21)))
 (= X10 (+ (* X5 S20) (* X7 S21)))
 (= X10 (- (* X5 S20) (* X7 S21)))
 (= X10 (- (* X7 S20) (* X5 S21)))
 (= X10 (+ (* X5 S20) (* X8 S21)))
 (= X10 (- (* X5 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X5 S21)))
 (= X10 (+ (* X5 S20) (* X9 S21)))
 (= X10 (- (* X5 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X5 S21)))
 (= X10 (+ (* X6 S20) S21))
 (= X10 (- (* X6 S20) S21))
 (= X10 (- S20 (* X6 S21)))
 (= X10 (+ (* X6 S20) (* X6 S21)))
 (= X10 (- (* X6 S20) (* X6 S21)))
 (= X10 (+ (* X6 S20) (* X7 S21)))
 (= X10 (- (* X6 S20) (* X7 S21)))
 (= X10 (- (* X7 S20) (* X6 S21)))
 (= X10 (+ (* X6 S20) (* X8 S21)))
 (= X10 (- (* X6 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X6 S21)))
 (= X10 (+ (* X6 S20) (* X9 S21)))
 (= X10 (- (* X6 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X6 S21)))
 (= X10 (+ (* X7 S20) S21))
 (= X10 (- (* X7 S20) S21))
 (= X10 (- S20 (* X7 S21)))
 (= X10 (+ (* X7 S20) (* X7 S21)))
 (= X10 (- (* X7 S20) (* X7 S21)))
 (= X10 (+ (* X7 S20) (* X8 S21)))
 (= X10 (- (* X7 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X7 S21)))
 (= X10 (+ (* X7 S20) (* X9 S21)))
 (= X10 (- (* X7 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X7 S21)))
 (= X10 (+ (* X8 S20) S21))
 (= X10 (- (* X8 S20) S21))
 (= X10 (- S20 (* X8 S21)))
 (= X10 (+ (* X8 S20) (* X8 S21)))
 (= X10 (- (* X8 S20) (* X8 S21)))
 (= X10 (+ (* X8 S20) (* X9 S21)))
 (= X10 (- (* X8 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X8 S21)))
 (= X10 (+ (* X9 S20) S21))
 (= X10 (- (* X9 S20) S21))
 (= X10 (- S20 (* X9 S21)))
 (= X10 (+ (* X9 S20) (* X9 S21)))
 (= X10 (- (* X9 S20) (* X9 S21)))
))
(assert (and (> X10 0) (< X10 4096) (power2 S20) (power2 S21)))
(assert (or
 (= X11 (+ (* X0 S22) S23))
 (= X11 (- (* X0 S22) S23))
 (= X11 (- S22 (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X0 S23)))
 (= X11 (- (* X0 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X1 S23)))
 (= X11 (- (* X0 S22) (* X1 S23)))
 (= X11 (- (* X1 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X2 S23)))
 (= X11 (- (* X0 S22) (* X2 S23)))
 (= X11 (- (* X2 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X3 S23)))
 (= X11 (- (* X0 S22) (* X3 S23)))
 (= X11 (- (* X3 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X4 S23)))
 (= X11 (- (* X0 S22) (* X4 S23)))
 (= X11 (- (* X4 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X5 S23)))
 (= X11 (- (* X0 S22) (* X5 S23)))
 (= X11 (- (* X5 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X6 S23)))
 (= X11 (- (* X0 S22) (* X6 S23)))
 (= X11 (- (* X6 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X7 S23)))
 (= X11 (- (* X0 S22) (* X7 S23)))
 (= X11 (- (* X7 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X8 S23)))
 (= X11 (- (* X0 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X9 S23)))
 (= X11 (- (* X0 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X0 S23)))
 (= X11 (+ (* X0 S22) (* X10 S23)))
 (= X11 (- (* X0 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X0 S23)))
 (= X11 (+ (* X1 S22) S23))
 (= X11 (- (* X1 S22) S23))
 (= X11 (- S22 (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X1 S23)))
 (= X11 (- (* X1 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X2 S23)))
 (= X11 (- (* X1 S22) (* X2 S23)))
 (= X11 (- (* X2 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X3 S23)))
 (= X11 (- (* X1 S22) (* X3 S23)))
 (= X11 (- (* X3 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X4 S23)))
 (= X11 (- (* X1 S22) (* X4 S23)))
 (= X11 (- (* X4 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X5 S23)))
 (= X11 (- (* X1 S22) (* X5 S23)))
 (= X11 (- (* X5 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X6 S23)))
 (= X11 (- (* X1 S22) (* X6 S23)))
 (= X11 (- (* X6 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X7 S23)))
 (= X11 (- (* X1 S22) (* X7 S23)))
 (= X11 (- (* X7 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X8 S23)))
 (= X11 (- (* X1 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X9 S23)))
 (= X11 (- (* X1 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X1 S23)))
 (= X11 (+ (* X1 S22) (* X10 S23)))
 (= X11 (- (* X1 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X1 S23)))
 (= X11 (+ (* X2 S22) S23))
 (= X11 (- (* X2 S22) S23))
 (= X11 (- S22 (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X2 S23)))
 (= X11 (- (* X2 S22) (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X3 S23)))
 (= X11 (- (* X2 S22) (* X3 S23)))
 (= X11 (- (* X3 S22) (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X4 S23)))
 (= X11 (- (* X2 S22) (* X4 S23)))
 (= X11 (- (* X4 S22) (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X5 S23)))
 (= X11 (- (* X2 S22) (* X5 S23)))
 (= X11 (- (* X5 S22) (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X6 S23)))
 (= X11 (- (* X2 S22) (* X6 S23)))
 (= X11 (- (* X6 S22) (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X7 S23)))
 (= X11 (- (* X2 S22) (* X7 S23)))
 (= X11 (- (* X7 S22) (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X8 S23)))
 (= X11 (- (* X2 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X9 S23)))
 (= X11 (- (* X2 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X2 S23)))
 (= X11 (+ (* X2 S22) (* X10 S23)))
 (= X11 (- (* X2 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X2 S23)))
 (= X11 (+ (* X3 S22) S23))
 (= X11 (- (* X3 S22) S23))
 (= X11 (- S22 (* X3 S23)))
 (= X11 (+ (* X3 S22) (* X3 S23)))
 (= X11 (- (* X3 S22) (* X3 S23)))
 (= X11 (+ (* X3 S22) (* X4 S23)))
 (= X11 (- (* X3 S22) (* X4 S23)))
 (= X11 (- (* X4 S22) (* X3 S23)))
 (= X11 (+ (* X3 S22) (* X5 S23)))
 (= X11 (- (* X3 S22) (* X5 S23)))
 (= X11 (- (* X5 S22) (* X3 S23)))
 (= X11 (+ (* X3 S22) (* X6 S23)))
 (= X11 (- (* X3 S22) (* X6 S23)))
 (= X11 (- (* X6 S22) (* X3 S23)))
 (= X11 (+ (* X3 S22) (* X7 S23)))
 (= X11 (- (* X3 S22) (* X7 S23)))
 (= X11 (- (* X7 S22) (* X3 S23)))
 (= X11 (+ (* X3 S22) (* X8 S23)))
 (= X11 (- (* X3 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X3 S23)))
 (= X11 (+ (* X3 S22) (* X9 S23)))
 (= X11 (- (* X3 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X3 S23)))
 (= X11 (+ (* X3 S22) (* X10 S23)))
 (= X11 (- (* X3 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X3 S23)))
 (= X11 (+ (* X4 S22) S23))
 (= X11 (- (* X4 S22) S23))
 (= X11 (- S22 (* X4 S23)))
 (= X11 (+ (* X4 S22) (* X4 S23)))
 (= X11 (- (* X4 S22) (* X4 S23)))
 (= X11 (+ (* X4 S22) (* X5 S23)))
 (= X11 (- (* X4 S22) (* X5 S23)))
 (= X11 (- (* X5 S22) (* X4 S23)))
 (= X11 (+ (* X4 S22) (* X6 S23)))
 (= X11 (- (* X4 S22) (* X6 S23)))
 (= X11 (- (* X6 S22) (* X4 S23)))
 (= X11 (+ (* X4 S22) (* X7 S23)))
 (= X11 (- (* X4 S22) (* X7 S23)))
 (= X11 (- (* X7 S22) (* X4 S23)))
 (= X11 (+ (* X4 S22) (* X8 S23)))
 (= X11 (- (* X4 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X4 S23)))
 (= X11 (+ (* X4 S22) (* X9 S23)))
 (= X11 (- (* X4 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X4 S23)))
 (= X11 (+ (* X4 S22) (* X10 S23)))
 (= X11 (- (* X4 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X4 S23)))
 (= X11 (+ (* X5 S22) S23))
 (= X11 (- (* X5 S22) S23))
 (= X11 (- S22 (* X5 S23)))
 (= X11 (+ (* X5 S22) (* X5 S23)))
 (= X11 (- (* X5 S22) (* X5 S23)))
 (= X11 (+ (* X5 S22) (* X6 S23)))
 (= X11 (- (* X5 S22) (* X6 S23)))
 (= X11 (- (* X6 S22) (* X5 S23)))
 (= X11 (+ (* X5 S22) (* X7 S23)))
 (= X11 (- (* X5 S22) (* X7 S23)))
 (= X11 (- (* X7 S22) (* X5 S23)))
 (= X11 (+ (* X5 S22) (* X8 S23)))
 (= X11 (- (* X5 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X5 S23)))
 (= X11 (+ (* X5 S22) (* X9 S23)))
 (= X11 (- (* X5 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X5 S23)))
 (= X11 (+ (* X5 S22) (* X10 S23)))
 (= X11 (- (* X5 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X5 S23)))
 (= X11 (+ (* X6 S22) S23))
 (= X11 (- (* X6 S22) S23))
 (= X11 (- S22 (* X6 S23)))
 (= X11 (+ (* X6 S22) (* X6 S23)))
 (= X11 (- (* X6 S22) (* X6 S23)))
 (= X11 (+ (* X6 S22) (* X7 S23)))
 (= X11 (- (* X6 S22) (* X7 S23)))
 (= X11 (- (* X7 S22) (* X6 S23)))
 (= X11 (+ (* X6 S22) (* X8 S23)))
 (= X11 (- (* X6 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X6 S23)))
 (= X11 (+ (* X6 S22) (* X9 S23)))
 (= X11 (- (* X6 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X6 S23)))
 (= X11 (+ (* X6 S22) (* X10 S23)))
 (= X11 (- (* X6 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X6 S23)))
 (= X11 (+ (* X7 S22) S23))
 (= X11 (- (* X7 S22) S23))
 (= X11 (- S22 (* X7 S23)))
 (= X11 (+ (* X7 S22) (* X7 S23)))
 (= X11 (- (* X7 S22) (* X7 S23)))
 (= X11 (+ (* X7 S22) (* X8 S23)))
 (= X11 (- (* X7 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X7 S23)))
 (= X11 (+ (* X7 S22) (* X9 S23)))
 (= X11 (- (* X7 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X7 S23)))
 (= X11 (+ (* X7 S22) (* X10 S23)))
 (= X11 (- (* X7 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X7 S23)))
 (= X11 (+ (* X8 S22) S23))
 (= X11 (- (* X8 S22) S23))
 (= X11 (- S22 (* X8 S23)))
 (= X11 (+ (* X8 S22) (* X8 S23)))
 (= X11 (- (* X8 S22) (* X8 S23)))
 (= X11 (+ (* X8 S22) (* X9 S23)))
 (= X11 (- (* X8 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X8 S23)))
 (= X11 (+ (* X8 S22) (* X10 S23)))
 (= X11 (- (* X8 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X8 S23)))
 (= X11 (+ (* X9 S22) S23))
 (= X11 (- (* X9 S22) S23))
 (= X11 (- S22 (* X9 S23)))
 (= X11 (+ (* X9 S22) (* X9 S23)))
 (= X11 (- (* X9 S22) (* X9 S23)))
 (= X11 (+ (* X9 S22) (* X10 S23)))
 (= X11 (- (* X9 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X9 S23)))
 (= X11 (+ (* X10 S22) S23))
 (= X11 (- (* X10 S22) S23))
 (= X11 (- S22 (* X10 S23)))
 (= X11 (+ (* X10 S22) (* X10 S23)))
 (= X11 (- (* X10 S22) (* X10 S23)))
))
(assert (and (> X11 0) (< X11 4096) (power2 S22) (power2 S23)))
(assert (or
 (= X1 857)
 (= X2 857)
 (= X3 857)
 (= X4 857)
 (= X5 857)
 (= X6 857)
 (= X7 857)
 (= X8 857)
 (= X9 857)
 (= X10 857)
 (= X11 857)
))
(assert (or
 (= X1 895)
 (= X2 895)
 (= X3 895)
 (= X4 895)
 (= X5 895)
 (= X6 895)
 (= X7 895)
 (= X8 895)
 (= X9 895)
 (= X10 895)
 (= X11 895)
))
(assert (or
 (= X1 35)
 (= X2 35)
 (= X3 35)
 (= X4 35)
 (= X5 35)
 (= X6 35)
 (= X7 35)
 (= X8 35)
 (= X9 35)
 (= X10 35)
 (= X11 35)
))
(assert (or
 (= X1 179)
 (= X2 179)
 (= X3 179)
 (= X4 179)
 (= X5 179)
 (= X6 179)
 (= X7 179)
 (= X8 179)
 (= X9 179)
 (= X10 179)
 (= X11 179)
))
(assert (or
 (= X1 341)
 (= X2 341)
 (= X3 341)
 (= X4 341)
 (= X5 341)
 (= X6 341)
 (= X7 341)
 (= X8 341)
 (= X9 341)
 (= X10 341)
 (= X11 341)
))
(assert (or
 (= X1 2043)
 (= X2 2043)
 (= X3 2043)
 (= X4 2043)
 (= X5 2043)
 (= X6 2043)
 (= X7 2043)
 (= X8 2043)
 (= X9 2043)
 (= X10 2043)
 (= X11 2043)
))
(assert (or
 (= X1 49)
 (= X2 49)
 (= X3 49)
 (= X4 49)
 (= X5 49)
 (= X6 49)
 (= X7 49)
 (= X8 49)
 (= X9 49)
 (= X10 49)
 (= X11 49)
))
(assert (or
 (= X1 623)
 (= X2 623)
 (= X3 623)
 (= X4 623)
 (= X5 623)
 (= X6 623)
 (= X7 623)
 (= X8 623)
 (= X9 623)
 (= X10 623)
 (= X11 623)
))
(assert (or
 (= X1 969)
 (= X2 969)
 (= X3 969)
 (= X4 969)
 (= X5 969)
 (= X6 969)
 (= X7 969)
 (= X8 969)
 (= X9 969)
 (= X10 969)
 (= X11 969)
))
(assert (or
 (= X1 1365)
 (= X2 1365)
 (= X3 1365)
 (= X4 1365)
 (= X5 1365)
 (= X6 1365)
 (= X7 1365)
 (= X8 1365)
 (= X9 1365)
 (= X10 1365)
 (= X11 1365)
))
(check-sat)
(exit)
