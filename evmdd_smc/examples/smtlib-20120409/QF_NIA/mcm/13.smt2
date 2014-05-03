(set-logic QF_NIA)
(set-info :source |
 more info in 'N. P. Lopes, L. Aksoy, V. Manquinho, J. Monteiro.
 Optimally Solving the MCM Problem Using Pseudo-Boolean Satisfiability.
 Technical Report RT/43/2010, INESC-ID, Nov. 2010'. |)
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
(define-fun power2 ((x Int)) Bool
  (or (= x 512) (= x 256) (= x 128) (= x 64) (= x 32) (= x 16) (= x 8) (= x 4) (= x 2) (= x 1)))
(assert (or
 (= X1 (+ S0 S1))
 (= X1 (- S0 S1))
 (= X1 (+ (* 15 S0) S1))
 (= X1 (- (* 15 S0) S1))
 (= X1 (- S0 (* 15 S1)))
 (= X1 (+ (* 15 S0) (* 15 S1)))
 (= X1 (- (* 15 S0) (* 15 S1)))
))
(assert (and (> X1 0) (< X1 1024) (power2 S0) (power2 S1)))
(assert (or
 (= X2 (+ (* 15 S2) S3))
 (= X2 (- (* 15 S2) S3))
 (= X2 (- S2 (* 15 S3)))
 (= X2 (+ (* 15 S2) (* 15 S3)))
 (= X2 (- (* 15 S2) (* 15 S3)))
 (= X2 (+ (* 15 S2) (* X1 S3)))
 (= X2 (- (* 15 S2) (* X1 S3)))
 (= X2 (- (* X1 S2) (* 15 S3)))
 (= X2 (+ (* X1 S2) S3))
 (= X2 (- (* X1 S2) S3))
 (= X2 (- S2 (* X1 S3)))
 (= X2 (+ (* X1 S2) (* X1 S3)))
 (= X2 (- (* X1 S2) (* X1 S3)))
))
(assert (and (> X2 0) (< X2 1024) (power2 S2) (power2 S3)))
(assert (or
 (= X3 (+ (* 15 S4) S5))
 (= X3 (- (* 15 S4) S5))
 (= X3 (- S4 (* 15 S5)))
 (= X3 (+ (* 15 S4) (* 15 S5)))
 (= X3 (- (* 15 S4) (* 15 S5)))
 (= X3 (+ (* 15 S4) (* X1 S5)))
 (= X3 (- (* 15 S4) (* X1 S5)))
 (= X3 (- (* X1 S4) (* 15 S5)))
 (= X3 (+ (* 15 S4) (* X2 S5)))
 (= X3 (- (* 15 S4) (* X2 S5)))
 (= X3 (- (* X2 S4) (* 15 S5)))
 (= X3 (+ (* X1 S4) S5))
 (= X3 (- (* X1 S4) S5))
 (= X3 (- S4 (* X1 S5)))
 (= X3 (+ (* X1 S4) (* X1 S5)))
 (= X3 (- (* X1 S4) (* X1 S5)))
 (= X3 (+ (* X1 S4) (* X2 S5)))
 (= X3 (- (* X1 S4) (* X2 S5)))
 (= X3 (- (* X2 S4) (* X1 S5)))
 (= X3 (+ (* X2 S4) S5))
 (= X3 (- (* X2 S4) S5))
 (= X3 (- S4 (* X2 S5)))
 (= X3 (+ (* X2 S4) (* X2 S5)))
 (= X3 (- (* X2 S4) (* X2 S5)))
))
(assert (and (> X3 0) (< X3 1024) (power2 S4) (power2 S5)))
(assert (or
 (= X4 (+ (* 15 S6) S7))
 (= X4 (- (* 15 S6) S7))
 (= X4 (- S6 (* 15 S7)))
 (= X4 (+ (* 15 S6) (* 15 S7)))
 (= X4 (- (* 15 S6) (* 15 S7)))
 (= X4 (+ (* 15 S6) (* X1 S7)))
 (= X4 (- (* 15 S6) (* X1 S7)))
 (= X4 (- (* X1 S6) (* 15 S7)))
 (= X4 (+ (* 15 S6) (* X2 S7)))
 (= X4 (- (* 15 S6) (* X2 S7)))
 (= X4 (- (* X2 S6) (* 15 S7)))
 (= X4 (+ (* 15 S6) (* X3 S7)))
 (= X4 (- (* 15 S6) (* X3 S7)))
 (= X4 (- (* X3 S6) (* 15 S7)))
 (= X4 (+ (* X1 S6) S7))
 (= X4 (- (* X1 S6) S7))
 (= X4 (- S6 (* X1 S7)))
 (= X4 (+ (* X1 S6) (* X1 S7)))
 (= X4 (- (* X1 S6) (* X1 S7)))
 (= X4 (+ (* X1 S6) (* X2 S7)))
 (= X4 (- (* X1 S6) (* X2 S7)))
 (= X4 (- (* X2 S6) (* X1 S7)))
 (= X4 (+ (* X1 S6) (* X3 S7)))
 (= X4 (- (* X1 S6) (* X3 S7)))
 (= X4 (- (* X3 S6) (* X1 S7)))
 (= X4 (+ (* X2 S6) S7))
 (= X4 (- (* X2 S6) S7))
 (= X4 (- S6 (* X2 S7)))
 (= X4 (+ (* X2 S6) (* X2 S7)))
 (= X4 (- (* X2 S6) (* X2 S7)))
 (= X4 (+ (* X2 S6) (* X3 S7)))
 (= X4 (- (* X2 S6) (* X3 S7)))
 (= X4 (- (* X3 S6) (* X2 S7)))
 (= X4 (+ (* X3 S6) S7))
 (= X4 (- (* X3 S6) S7))
 (= X4 (- S6 (* X3 S7)))
 (= X4 (+ (* X3 S6) (* X3 S7)))
 (= X4 (- (* X3 S6) (* X3 S7)))
))
(assert (and (> X4 0) (< X4 1024) (power2 S6) (power2 S7)))
(assert (or
 (= X5 (+ (* 15 S8) S9))
 (= X5 (- (* 15 S8) S9))
 (= X5 (- S8 (* 15 S9)))
 (= X5 (+ (* 15 S8) (* 15 S9)))
 (= X5 (- (* 15 S8) (* 15 S9)))
 (= X5 (+ (* 15 S8) (* X1 S9)))
 (= X5 (- (* 15 S8) (* X1 S9)))
 (= X5 (- (* X1 S8) (* 15 S9)))
 (= X5 (+ (* 15 S8) (* X2 S9)))
 (= X5 (- (* 15 S8) (* X2 S9)))
 (= X5 (- (* X2 S8) (* 15 S9)))
 (= X5 (+ (* 15 S8) (* X3 S9)))
 (= X5 (- (* 15 S8) (* X3 S9)))
 (= X5 (- (* X3 S8) (* 15 S9)))
 (= X5 (+ (* 15 S8) (* X4 S9)))
 (= X5 (- (* 15 S8) (* X4 S9)))
 (= X5 (- (* X4 S8) (* 15 S9)))
 (= X5 (+ (* X1 S8) S9))
 (= X5 (- (* X1 S8) S9))
 (= X5 (- S8 (* X1 S9)))
 (= X5 (+ (* X1 S8) (* X1 S9)))
 (= X5 (- (* X1 S8) (* X1 S9)))
 (= X5 (+ (* X1 S8) (* X2 S9)))
 (= X5 (- (* X1 S8) (* X2 S9)))
 (= X5 (- (* X2 S8) (* X1 S9)))
 (= X5 (+ (* X1 S8) (* X3 S9)))
 (= X5 (- (* X1 S8) (* X3 S9)))
 (= X5 (- (* X3 S8) (* X1 S9)))
 (= X5 (+ (* X1 S8) (* X4 S9)))
 (= X5 (- (* X1 S8) (* X4 S9)))
 (= X5 (- (* X4 S8) (* X1 S9)))
 (= X5 (+ (* X2 S8) S9))
 (= X5 (- (* X2 S8) S9))
 (= X5 (- S8 (* X2 S9)))
 (= X5 (+ (* X2 S8) (* X2 S9)))
 (= X5 (- (* X2 S8) (* X2 S9)))
 (= X5 (+ (* X2 S8) (* X3 S9)))
 (= X5 (- (* X2 S8) (* X3 S9)))
 (= X5 (- (* X3 S8) (* X2 S9)))
 (= X5 (+ (* X2 S8) (* X4 S9)))
 (= X5 (- (* X2 S8) (* X4 S9)))
 (= X5 (- (* X4 S8) (* X2 S9)))
 (= X5 (+ (* X3 S8) S9))
 (= X5 (- (* X3 S8) S9))
 (= X5 (- S8 (* X3 S9)))
 (= X5 (+ (* X3 S8) (* X3 S9)))
 (= X5 (- (* X3 S8) (* X3 S9)))
 (= X5 (+ (* X3 S8) (* X4 S9)))
 (= X5 (- (* X3 S8) (* X4 S9)))
 (= X5 (- (* X4 S8) (* X3 S9)))
 (= X5 (+ (* X4 S8) S9))
 (= X5 (- (* X4 S8) S9))
 (= X5 (- S8 (* X4 S9)))
 (= X5 (+ (* X4 S8) (* X4 S9)))
 (= X5 (- (* X4 S8) (* X4 S9)))
))
(assert (and (> X5 0) (< X5 1024) (power2 S8) (power2 S9)))
(assert (or
 (= X6 (+ (* 15 S10) S11))
 (= X6 (- (* 15 S10) S11))
 (= X6 (- S10 (* 15 S11)))
 (= X6 (+ (* 15 S10) (* 15 S11)))
 (= X6 (- (* 15 S10) (* 15 S11)))
 (= X6 (+ (* 15 S10) (* X1 S11)))
 (= X6 (- (* 15 S10) (* X1 S11)))
 (= X6 (- (* X1 S10) (* 15 S11)))
 (= X6 (+ (* 15 S10) (* X2 S11)))
 (= X6 (- (* 15 S10) (* X2 S11)))
 (= X6 (- (* X2 S10) (* 15 S11)))
 (= X6 (+ (* 15 S10) (* X3 S11)))
 (= X6 (- (* 15 S10) (* X3 S11)))
 (= X6 (- (* X3 S10) (* 15 S11)))
 (= X6 (+ (* 15 S10) (* X4 S11)))
 (= X6 (- (* 15 S10) (* X4 S11)))
 (= X6 (- (* X4 S10) (* 15 S11)))
 (= X6 (+ (* 15 S10) (* X5 S11)))
 (= X6 (- (* 15 S10) (* X5 S11)))
 (= X6 (- (* X5 S10) (* 15 S11)))
 (= X6 (+ (* X1 S10) S11))
 (= X6 (- (* X1 S10) S11))
 (= X6 (- S10 (* X1 S11)))
 (= X6 (+ (* X1 S10) (* X1 S11)))
 (= X6 (- (* X1 S10) (* X1 S11)))
 (= X6 (+ (* X1 S10) (* X2 S11)))
 (= X6 (- (* X1 S10) (* X2 S11)))
 (= X6 (- (* X2 S10) (* X1 S11)))
 (= X6 (+ (* X1 S10) (* X3 S11)))
 (= X6 (- (* X1 S10) (* X3 S11)))
 (= X6 (- (* X3 S10) (* X1 S11)))
 (= X6 (+ (* X1 S10) (* X4 S11)))
 (= X6 (- (* X1 S10) (* X4 S11)))
 (= X6 (- (* X4 S10) (* X1 S11)))
 (= X6 (+ (* X1 S10) (* X5 S11)))
 (= X6 (- (* X1 S10) (* X5 S11)))
 (= X6 (- (* X5 S10) (* X1 S11)))
 (= X6 (+ (* X2 S10) S11))
 (= X6 (- (* X2 S10) S11))
 (= X6 (- S10 (* X2 S11)))
 (= X6 (+ (* X2 S10) (* X2 S11)))
 (= X6 (- (* X2 S10) (* X2 S11)))
 (= X6 (+ (* X2 S10) (* X3 S11)))
 (= X6 (- (* X2 S10) (* X3 S11)))
 (= X6 (- (* X3 S10) (* X2 S11)))
 (= X6 (+ (* X2 S10) (* X4 S11)))
 (= X6 (- (* X2 S10) (* X4 S11)))
 (= X6 (- (* X4 S10) (* X2 S11)))
 (= X6 (+ (* X2 S10) (* X5 S11)))
 (= X6 (- (* X2 S10) (* X5 S11)))
 (= X6 (- (* X5 S10) (* X2 S11)))
 (= X6 (+ (* X3 S10) S11))
 (= X6 (- (* X3 S10) S11))
 (= X6 (- S10 (* X3 S11)))
 (= X6 (+ (* X3 S10) (* X3 S11)))
 (= X6 (- (* X3 S10) (* X3 S11)))
 (= X6 (+ (* X3 S10) (* X4 S11)))
 (= X6 (- (* X3 S10) (* X4 S11)))
 (= X6 (- (* X4 S10) (* X3 S11)))
 (= X6 (+ (* X3 S10) (* X5 S11)))
 (= X6 (- (* X3 S10) (* X5 S11)))
 (= X6 (- (* X5 S10) (* X3 S11)))
 (= X6 (+ (* X4 S10) S11))
 (= X6 (- (* X4 S10) S11))
 (= X6 (- S10 (* X4 S11)))
 (= X6 (+ (* X4 S10) (* X4 S11)))
 (= X6 (- (* X4 S10) (* X4 S11)))
 (= X6 (+ (* X4 S10) (* X5 S11)))
 (= X6 (- (* X4 S10) (* X5 S11)))
 (= X6 (- (* X5 S10) (* X4 S11)))
 (= X6 (+ (* X5 S10) S11))
 (= X6 (- (* X5 S10) S11))
 (= X6 (- S10 (* X5 S11)))
 (= X6 (+ (* X5 S10) (* X5 S11)))
 (= X6 (- (* X5 S10) (* X5 S11)))
))
(assert (and (> X6 0) (< X6 1024) (power2 S10) (power2 S11)))
(assert (or
 (= X7 (+ (* 15 S12) S13))
 (= X7 (- (* 15 S12) S13))
 (= X7 (- S12 (* 15 S13)))
 (= X7 (+ (* 15 S12) (* 15 S13)))
 (= X7 (- (* 15 S12) (* 15 S13)))
 (= X7 (+ (* 15 S12) (* X1 S13)))
 (= X7 (- (* 15 S12) (* X1 S13)))
 (= X7 (- (* X1 S12) (* 15 S13)))
 (= X7 (+ (* 15 S12) (* X2 S13)))
 (= X7 (- (* 15 S12) (* X2 S13)))
 (= X7 (- (* X2 S12) (* 15 S13)))
 (= X7 (+ (* 15 S12) (* X3 S13)))
 (= X7 (- (* 15 S12) (* X3 S13)))
 (= X7 (- (* X3 S12) (* 15 S13)))
 (= X7 (+ (* 15 S12) (* X4 S13)))
 (= X7 (- (* 15 S12) (* X4 S13)))
 (= X7 (- (* X4 S12) (* 15 S13)))
 (= X7 (+ (* 15 S12) (* X5 S13)))
 (= X7 (- (* 15 S12) (* X5 S13)))
 (= X7 (- (* X5 S12) (* 15 S13)))
 (= X7 (+ (* 15 S12) (* X6 S13)))
 (= X7 (- (* 15 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* 15 S13)))
 (= X7 (+ (* X1 S12) S13))
 (= X7 (- (* X1 S12) S13))
 (= X7 (- S12 (* X1 S13)))
 (= X7 (+ (* X1 S12) (* X1 S13)))
 (= X7 (- (* X1 S12) (* X1 S13)))
 (= X7 (+ (* X1 S12) (* X2 S13)))
 (= X7 (- (* X1 S12) (* X2 S13)))
 (= X7 (- (* X2 S12) (* X1 S13)))
 (= X7 (+ (* X1 S12) (* X3 S13)))
 (= X7 (- (* X1 S12) (* X3 S13)))
 (= X7 (- (* X3 S12) (* X1 S13)))
 (= X7 (+ (* X1 S12) (* X4 S13)))
 (= X7 (- (* X1 S12) (* X4 S13)))
 (= X7 (- (* X4 S12) (* X1 S13)))
 (= X7 (+ (* X1 S12) (* X5 S13)))
 (= X7 (- (* X1 S12) (* X5 S13)))
 (= X7 (- (* X5 S12) (* X1 S13)))
 (= X7 (+ (* X1 S12) (* X6 S13)))
 (= X7 (- (* X1 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* X1 S13)))
 (= X7 (+ (* X2 S12) S13))
 (= X7 (- (* X2 S12) S13))
 (= X7 (- S12 (* X2 S13)))
 (= X7 (+ (* X2 S12) (* X2 S13)))
 (= X7 (- (* X2 S12) (* X2 S13)))
 (= X7 (+ (* X2 S12) (* X3 S13)))
 (= X7 (- (* X2 S12) (* X3 S13)))
 (= X7 (- (* X3 S12) (* X2 S13)))
 (= X7 (+ (* X2 S12) (* X4 S13)))
 (= X7 (- (* X2 S12) (* X4 S13)))
 (= X7 (- (* X4 S12) (* X2 S13)))
 (= X7 (+ (* X2 S12) (* X5 S13)))
 (= X7 (- (* X2 S12) (* X5 S13)))
 (= X7 (- (* X5 S12) (* X2 S13)))
 (= X7 (+ (* X2 S12) (* X6 S13)))
 (= X7 (- (* X2 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* X2 S13)))
 (= X7 (+ (* X3 S12) S13))
 (= X7 (- (* X3 S12) S13))
 (= X7 (- S12 (* X3 S13)))
 (= X7 (+ (* X3 S12) (* X3 S13)))
 (= X7 (- (* X3 S12) (* X3 S13)))
 (= X7 (+ (* X3 S12) (* X4 S13)))
 (= X7 (- (* X3 S12) (* X4 S13)))
 (= X7 (- (* X4 S12) (* X3 S13)))
 (= X7 (+ (* X3 S12) (* X5 S13)))
 (= X7 (- (* X3 S12) (* X5 S13)))
 (= X7 (- (* X5 S12) (* X3 S13)))
 (= X7 (+ (* X3 S12) (* X6 S13)))
 (= X7 (- (* X3 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* X3 S13)))
 (= X7 (+ (* X4 S12) S13))
 (= X7 (- (* X4 S12) S13))
 (= X7 (- S12 (* X4 S13)))
 (= X7 (+ (* X4 S12) (* X4 S13)))
 (= X7 (- (* X4 S12) (* X4 S13)))
 (= X7 (+ (* X4 S12) (* X5 S13)))
 (= X7 (- (* X4 S12) (* X5 S13)))
 (= X7 (- (* X5 S12) (* X4 S13)))
 (= X7 (+ (* X4 S12) (* X6 S13)))
 (= X7 (- (* X4 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* X4 S13)))
 (= X7 (+ (* X5 S12) S13))
 (= X7 (- (* X5 S12) S13))
 (= X7 (- S12 (* X5 S13)))
 (= X7 (+ (* X5 S12) (* X5 S13)))
 (= X7 (- (* X5 S12) (* X5 S13)))
 (= X7 (+ (* X5 S12) (* X6 S13)))
 (= X7 (- (* X5 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* X5 S13)))
 (= X7 (+ (* X6 S12) S13))
 (= X7 (- (* X6 S12) S13))
 (= X7 (- S12 (* X6 S13)))
 (= X7 (+ (* X6 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* X6 S13)))
))
(assert (and (> X7 0) (< X7 1024) (power2 S12) (power2 S13)))
(assert (or
 (= X8 (+ (* 15 S14) S15))
 (= X8 (- (* 15 S14) S15))
 (= X8 (- S14 (* 15 S15)))
 (= X8 (+ (* 15 S14) (* 15 S15)))
 (= X8 (- (* 15 S14) (* 15 S15)))
 (= X8 (+ (* 15 S14) (* X1 S15)))
 (= X8 (- (* 15 S14) (* X1 S15)))
 (= X8 (- (* X1 S14) (* 15 S15)))
 (= X8 (+ (* 15 S14) (* X2 S15)))
 (= X8 (- (* 15 S14) (* X2 S15)))
 (= X8 (- (* X2 S14) (* 15 S15)))
 (= X8 (+ (* 15 S14) (* X3 S15)))
 (= X8 (- (* 15 S14) (* X3 S15)))
 (= X8 (- (* X3 S14) (* 15 S15)))
 (= X8 (+ (* 15 S14) (* X4 S15)))
 (= X8 (- (* 15 S14) (* X4 S15)))
 (= X8 (- (* X4 S14) (* 15 S15)))
 (= X8 (+ (* 15 S14) (* X5 S15)))
 (= X8 (- (* 15 S14) (* X5 S15)))
 (= X8 (- (* X5 S14) (* 15 S15)))
 (= X8 (+ (* 15 S14) (* X6 S15)))
 (= X8 (- (* 15 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* 15 S15)))
 (= X8 (+ (* 15 S14) (* X7 S15)))
 (= X8 (- (* 15 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* 15 S15)))
 (= X8 (+ (* X1 S14) S15))
 (= X8 (- (* X1 S14) S15))
 (= X8 (- S14 (* X1 S15)))
 (= X8 (+ (* X1 S14) (* X1 S15)))
 (= X8 (- (* X1 S14) (* X1 S15)))
 (= X8 (+ (* X1 S14) (* X2 S15)))
 (= X8 (- (* X1 S14) (* X2 S15)))
 (= X8 (- (* X2 S14) (* X1 S15)))
 (= X8 (+ (* X1 S14) (* X3 S15)))
 (= X8 (- (* X1 S14) (* X3 S15)))
 (= X8 (- (* X3 S14) (* X1 S15)))
 (= X8 (+ (* X1 S14) (* X4 S15)))
 (= X8 (- (* X1 S14) (* X4 S15)))
 (= X8 (- (* X4 S14) (* X1 S15)))
 (= X8 (+ (* X1 S14) (* X5 S15)))
 (= X8 (- (* X1 S14) (* X5 S15)))
 (= X8 (- (* X5 S14) (* X1 S15)))
 (= X8 (+ (* X1 S14) (* X6 S15)))
 (= X8 (- (* X1 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* X1 S15)))
 (= X8 (+ (* X1 S14) (* X7 S15)))
 (= X8 (- (* X1 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* X1 S15)))
 (= X8 (+ (* X2 S14) S15))
 (= X8 (- (* X2 S14) S15))
 (= X8 (- S14 (* X2 S15)))
 (= X8 (+ (* X2 S14) (* X2 S15)))
 (= X8 (- (* X2 S14) (* X2 S15)))
 (= X8 (+ (* X2 S14) (* X3 S15)))
 (= X8 (- (* X2 S14) (* X3 S15)))
 (= X8 (- (* X3 S14) (* X2 S15)))
 (= X8 (+ (* X2 S14) (* X4 S15)))
 (= X8 (- (* X2 S14) (* X4 S15)))
 (= X8 (- (* X4 S14) (* X2 S15)))
 (= X8 (+ (* X2 S14) (* X5 S15)))
 (= X8 (- (* X2 S14) (* X5 S15)))
 (= X8 (- (* X5 S14) (* X2 S15)))
 (= X8 (+ (* X2 S14) (* X6 S15)))
 (= X8 (- (* X2 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* X2 S15)))
 (= X8 (+ (* X2 S14) (* X7 S15)))
 (= X8 (- (* X2 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* X2 S15)))
 (= X8 (+ (* X3 S14) S15))
 (= X8 (- (* X3 S14) S15))
 (= X8 (- S14 (* X3 S15)))
 (= X8 (+ (* X3 S14) (* X3 S15)))
 (= X8 (- (* X3 S14) (* X3 S15)))
 (= X8 (+ (* X3 S14) (* X4 S15)))
 (= X8 (- (* X3 S14) (* X4 S15)))
 (= X8 (- (* X4 S14) (* X3 S15)))
 (= X8 (+ (* X3 S14) (* X5 S15)))
 (= X8 (- (* X3 S14) (* X5 S15)))
 (= X8 (- (* X5 S14) (* X3 S15)))
 (= X8 (+ (* X3 S14) (* X6 S15)))
 (= X8 (- (* X3 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* X3 S15)))
 (= X8 (+ (* X3 S14) (* X7 S15)))
 (= X8 (- (* X3 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* X3 S15)))
 (= X8 (+ (* X4 S14) S15))
 (= X8 (- (* X4 S14) S15))
 (= X8 (- S14 (* X4 S15)))
 (= X8 (+ (* X4 S14) (* X4 S15)))
 (= X8 (- (* X4 S14) (* X4 S15)))
 (= X8 (+ (* X4 S14) (* X5 S15)))
 (= X8 (- (* X4 S14) (* X5 S15)))
 (= X8 (- (* X5 S14) (* X4 S15)))
 (= X8 (+ (* X4 S14) (* X6 S15)))
 (= X8 (- (* X4 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* X4 S15)))
 (= X8 (+ (* X4 S14) (* X7 S15)))
 (= X8 (- (* X4 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* X4 S15)))
 (= X8 (+ (* X5 S14) S15))
 (= X8 (- (* X5 S14) S15))
 (= X8 (- S14 (* X5 S15)))
 (= X8 (+ (* X5 S14) (* X5 S15)))
 (= X8 (- (* X5 S14) (* X5 S15)))
 (= X8 (+ (* X5 S14) (* X6 S15)))
 (= X8 (- (* X5 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* X5 S15)))
 (= X8 (+ (* X5 S14) (* X7 S15)))
 (= X8 (- (* X5 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* X5 S15)))
 (= X8 (+ (* X6 S14) S15))
 (= X8 (- (* X6 S14) S15))
 (= X8 (- S14 (* X6 S15)))
 (= X8 (+ (* X6 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* X6 S15)))
 (= X8 (+ (* X6 S14) (* X7 S15)))
 (= X8 (- (* X6 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* X6 S15)))
 (= X8 (+ (* X7 S14) S15))
 (= X8 (- (* X7 S14) S15))
 (= X8 (- S14 (* X7 S15)))
 (= X8 (+ (* X7 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* X7 S15)))
))
(assert (and (> X8 0) (< X8 1024) (power2 S14) (power2 S15)))
(assert (or
 (= X9 (+ (* 15 S16) S17))
 (= X9 (- (* 15 S16) S17))
 (= X9 (- S16 (* 15 S17)))
 (= X9 (+ (* 15 S16) (* 15 S17)))
 (= X9 (- (* 15 S16) (* 15 S17)))
 (= X9 (+ (* 15 S16) (* X1 S17)))
 (= X9 (- (* 15 S16) (* X1 S17)))
 (= X9 (- (* X1 S16) (* 15 S17)))
 (= X9 (+ (* 15 S16) (* X2 S17)))
 (= X9 (- (* 15 S16) (* X2 S17)))
 (= X9 (- (* X2 S16) (* 15 S17)))
 (= X9 (+ (* 15 S16) (* X3 S17)))
 (= X9 (- (* 15 S16) (* X3 S17)))
 (= X9 (- (* X3 S16) (* 15 S17)))
 (= X9 (+ (* 15 S16) (* X4 S17)))
 (= X9 (- (* 15 S16) (* X4 S17)))
 (= X9 (- (* X4 S16) (* 15 S17)))
 (= X9 (+ (* 15 S16) (* X5 S17)))
 (= X9 (- (* 15 S16) (* X5 S17)))
 (= X9 (- (* X5 S16) (* 15 S17)))
 (= X9 (+ (* 15 S16) (* X6 S17)))
 (= X9 (- (* 15 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* 15 S17)))
 (= X9 (+ (* 15 S16) (* X7 S17)))
 (= X9 (- (* 15 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* 15 S17)))
 (= X9 (+ (* 15 S16) (* X8 S17)))
 (= X9 (- (* 15 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* 15 S17)))
 (= X9 (+ (* X1 S16) S17))
 (= X9 (- (* X1 S16) S17))
 (= X9 (- S16 (* X1 S17)))
 (= X9 (+ (* X1 S16) (* X1 S17)))
 (= X9 (- (* X1 S16) (* X1 S17)))
 (= X9 (+ (* X1 S16) (* X2 S17)))
 (= X9 (- (* X1 S16) (* X2 S17)))
 (= X9 (- (* X2 S16) (* X1 S17)))
 (= X9 (+ (* X1 S16) (* X3 S17)))
 (= X9 (- (* X1 S16) (* X3 S17)))
 (= X9 (- (* X3 S16) (* X1 S17)))
 (= X9 (+ (* X1 S16) (* X4 S17)))
 (= X9 (- (* X1 S16) (* X4 S17)))
 (= X9 (- (* X4 S16) (* X1 S17)))
 (= X9 (+ (* X1 S16) (* X5 S17)))
 (= X9 (- (* X1 S16) (* X5 S17)))
 (= X9 (- (* X5 S16) (* X1 S17)))
 (= X9 (+ (* X1 S16) (* X6 S17)))
 (= X9 (- (* X1 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* X1 S17)))
 (= X9 (+ (* X1 S16) (* X7 S17)))
 (= X9 (- (* X1 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* X1 S17)))
 (= X9 (+ (* X1 S16) (* X8 S17)))
 (= X9 (- (* X1 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* X1 S17)))
 (= X9 (+ (* X2 S16) S17))
 (= X9 (- (* X2 S16) S17))
 (= X9 (- S16 (* X2 S17)))
 (= X9 (+ (* X2 S16) (* X2 S17)))
 (= X9 (- (* X2 S16) (* X2 S17)))
 (= X9 (+ (* X2 S16) (* X3 S17)))
 (= X9 (- (* X2 S16) (* X3 S17)))
 (= X9 (- (* X3 S16) (* X2 S17)))
 (= X9 (+ (* X2 S16) (* X4 S17)))
 (= X9 (- (* X2 S16) (* X4 S17)))
 (= X9 (- (* X4 S16) (* X2 S17)))
 (= X9 (+ (* X2 S16) (* X5 S17)))
 (= X9 (- (* X2 S16) (* X5 S17)))
 (= X9 (- (* X5 S16) (* X2 S17)))
 (= X9 (+ (* X2 S16) (* X6 S17)))
 (= X9 (- (* X2 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* X2 S17)))
 (= X9 (+ (* X2 S16) (* X7 S17)))
 (= X9 (- (* X2 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* X2 S17)))
 (= X9 (+ (* X2 S16) (* X8 S17)))
 (= X9 (- (* X2 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* X2 S17)))
 (= X9 (+ (* X3 S16) S17))
 (= X9 (- (* X3 S16) S17))
 (= X9 (- S16 (* X3 S17)))
 (= X9 (+ (* X3 S16) (* X3 S17)))
 (= X9 (- (* X3 S16) (* X3 S17)))
 (= X9 (+ (* X3 S16) (* X4 S17)))
 (= X9 (- (* X3 S16) (* X4 S17)))
 (= X9 (- (* X4 S16) (* X3 S17)))
 (= X9 (+ (* X3 S16) (* X5 S17)))
 (= X9 (- (* X3 S16) (* X5 S17)))
 (= X9 (- (* X5 S16) (* X3 S17)))
 (= X9 (+ (* X3 S16) (* X6 S17)))
 (= X9 (- (* X3 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* X3 S17)))
 (= X9 (+ (* X3 S16) (* X7 S17)))
 (= X9 (- (* X3 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* X3 S17)))
 (= X9 (+ (* X3 S16) (* X8 S17)))
 (= X9 (- (* X3 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* X3 S17)))
 (= X9 (+ (* X4 S16) S17))
 (= X9 (- (* X4 S16) S17))
 (= X9 (- S16 (* X4 S17)))
 (= X9 (+ (* X4 S16) (* X4 S17)))
 (= X9 (- (* X4 S16) (* X4 S17)))
 (= X9 (+ (* X4 S16) (* X5 S17)))
 (= X9 (- (* X4 S16) (* X5 S17)))
 (= X9 (- (* X5 S16) (* X4 S17)))
 (= X9 (+ (* X4 S16) (* X6 S17)))
 (= X9 (- (* X4 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* X4 S17)))
 (= X9 (+ (* X4 S16) (* X7 S17)))
 (= X9 (- (* X4 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* X4 S17)))
 (= X9 (+ (* X4 S16) (* X8 S17)))
 (= X9 (- (* X4 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* X4 S17)))
 (= X9 (+ (* X5 S16) S17))
 (= X9 (- (* X5 S16) S17))
 (= X9 (- S16 (* X5 S17)))
 (= X9 (+ (* X5 S16) (* X5 S17)))
 (= X9 (- (* X5 S16) (* X5 S17)))
 (= X9 (+ (* X5 S16) (* X6 S17)))
 (= X9 (- (* X5 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* X5 S17)))
 (= X9 (+ (* X5 S16) (* X7 S17)))
 (= X9 (- (* X5 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* X5 S17)))
 (= X9 (+ (* X5 S16) (* X8 S17)))
 (= X9 (- (* X5 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* X5 S17)))
 (= X9 (+ (* X6 S16) S17))
 (= X9 (- (* X6 S16) S17))
 (= X9 (- S16 (* X6 S17)))
 (= X9 (+ (* X6 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* X6 S17)))
 (= X9 (+ (* X6 S16) (* X7 S17)))
 (= X9 (- (* X6 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* X6 S17)))
 (= X9 (+ (* X6 S16) (* X8 S17)))
 (= X9 (- (* X6 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* X6 S17)))
 (= X9 (+ (* X7 S16) S17))
 (= X9 (- (* X7 S16) S17))
 (= X9 (- S16 (* X7 S17)))
 (= X9 (+ (* X7 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* X7 S17)))
 (= X9 (+ (* X7 S16) (* X8 S17)))
 (= X9 (- (* X7 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* X7 S17)))
 (= X9 (+ (* X8 S16) S17))
 (= X9 (- (* X8 S16) S17))
 (= X9 (- S16 (* X8 S17)))
 (= X9 (+ (* X8 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* X8 S17)))
))
(assert (and (> X9 0) (< X9 1024) (power2 S16) (power2 S17)))
(assert (or
 (= X10 (+ (* 15 S18) S19))
 (= X10 (- (* 15 S18) S19))
 (= X10 (- S18 (* 15 S19)))
 (= X10 (+ (* 15 S18) (* 15 S19)))
 (= X10 (- (* 15 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X1 S19)))
 (= X10 (- (* 15 S18) (* X1 S19)))
 (= X10 (- (* X1 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X2 S19)))
 (= X10 (- (* 15 S18) (* X2 S19)))
 (= X10 (- (* X2 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X3 S19)))
 (= X10 (- (* 15 S18) (* X3 S19)))
 (= X10 (- (* X3 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X4 S19)))
 (= X10 (- (* 15 S18) (* X4 S19)))
 (= X10 (- (* X4 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X5 S19)))
 (= X10 (- (* 15 S18) (* X5 S19)))
 (= X10 (- (* X5 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X6 S19)))
 (= X10 (- (* 15 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X7 S19)))
 (= X10 (- (* 15 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X8 S19)))
 (= X10 (- (* 15 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* 15 S19)))
 (= X10 (+ (* 15 S18) (* X9 S19)))
 (= X10 (- (* 15 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* 15 S19)))
 (= X10 (+ (* X1 S18) S19))
 (= X10 (- (* X1 S18) S19))
 (= X10 (- S18 (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X1 S19)))
 (= X10 (- (* X1 S18) (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X2 S19)))
 (= X10 (- (* X1 S18) (* X2 S19)))
 (= X10 (- (* X2 S18) (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X3 S19)))
 (= X10 (- (* X1 S18) (* X3 S19)))
 (= X10 (- (* X3 S18) (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X4 S19)))
 (= X10 (- (* X1 S18) (* X4 S19)))
 (= X10 (- (* X4 S18) (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X5 S19)))
 (= X10 (- (* X1 S18) (* X5 S19)))
 (= X10 (- (* X5 S18) (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X6 S19)))
 (= X10 (- (* X1 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X7 S19)))
 (= X10 (- (* X1 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X8 S19)))
 (= X10 (- (* X1 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* X1 S19)))
 (= X10 (+ (* X1 S18) (* X9 S19)))
 (= X10 (- (* X1 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X1 S19)))
 (= X10 (+ (* X2 S18) S19))
 (= X10 (- (* X2 S18) S19))
 (= X10 (- S18 (* X2 S19)))
 (= X10 (+ (* X2 S18) (* X2 S19)))
 (= X10 (- (* X2 S18) (* X2 S19)))
 (= X10 (+ (* X2 S18) (* X3 S19)))
 (= X10 (- (* X2 S18) (* X3 S19)))
 (= X10 (- (* X3 S18) (* X2 S19)))
 (= X10 (+ (* X2 S18) (* X4 S19)))
 (= X10 (- (* X2 S18) (* X4 S19)))
 (= X10 (- (* X4 S18) (* X2 S19)))
 (= X10 (+ (* X2 S18) (* X5 S19)))
 (= X10 (- (* X2 S18) (* X5 S19)))
 (= X10 (- (* X5 S18) (* X2 S19)))
 (= X10 (+ (* X2 S18) (* X6 S19)))
 (= X10 (- (* X2 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* X2 S19)))
 (= X10 (+ (* X2 S18) (* X7 S19)))
 (= X10 (- (* X2 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* X2 S19)))
 (= X10 (+ (* X2 S18) (* X8 S19)))
 (= X10 (- (* X2 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* X2 S19)))
 (= X10 (+ (* X2 S18) (* X9 S19)))
 (= X10 (- (* X2 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X2 S19)))
 (= X10 (+ (* X3 S18) S19))
 (= X10 (- (* X3 S18) S19))
 (= X10 (- S18 (* X3 S19)))
 (= X10 (+ (* X3 S18) (* X3 S19)))
 (= X10 (- (* X3 S18) (* X3 S19)))
 (= X10 (+ (* X3 S18) (* X4 S19)))
 (= X10 (- (* X3 S18) (* X4 S19)))
 (= X10 (- (* X4 S18) (* X3 S19)))
 (= X10 (+ (* X3 S18) (* X5 S19)))
 (= X10 (- (* X3 S18) (* X5 S19)))
 (= X10 (- (* X5 S18) (* X3 S19)))
 (= X10 (+ (* X3 S18) (* X6 S19)))
 (= X10 (- (* X3 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* X3 S19)))
 (= X10 (+ (* X3 S18) (* X7 S19)))
 (= X10 (- (* X3 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* X3 S19)))
 (= X10 (+ (* X3 S18) (* X8 S19)))
 (= X10 (- (* X3 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* X3 S19)))
 (= X10 (+ (* X3 S18) (* X9 S19)))
 (= X10 (- (* X3 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X3 S19)))
 (= X10 (+ (* X4 S18) S19))
 (= X10 (- (* X4 S18) S19))
 (= X10 (- S18 (* X4 S19)))
 (= X10 (+ (* X4 S18) (* X4 S19)))
 (= X10 (- (* X4 S18) (* X4 S19)))
 (= X10 (+ (* X4 S18) (* X5 S19)))
 (= X10 (- (* X4 S18) (* X5 S19)))
 (= X10 (- (* X5 S18) (* X4 S19)))
 (= X10 (+ (* X4 S18) (* X6 S19)))
 (= X10 (- (* X4 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* X4 S19)))
 (= X10 (+ (* X4 S18) (* X7 S19)))
 (= X10 (- (* X4 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* X4 S19)))
 (= X10 (+ (* X4 S18) (* X8 S19)))
 (= X10 (- (* X4 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* X4 S19)))
 (= X10 (+ (* X4 S18) (* X9 S19)))
 (= X10 (- (* X4 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X4 S19)))
 (= X10 (+ (* X5 S18) S19))
 (= X10 (- (* X5 S18) S19))
 (= X10 (- S18 (* X5 S19)))
 (= X10 (+ (* X5 S18) (* X5 S19)))
 (= X10 (- (* X5 S18) (* X5 S19)))
 (= X10 (+ (* X5 S18) (* X6 S19)))
 (= X10 (- (* X5 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* X5 S19)))
 (= X10 (+ (* X5 S18) (* X7 S19)))
 (= X10 (- (* X5 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* X5 S19)))
 (= X10 (+ (* X5 S18) (* X8 S19)))
 (= X10 (- (* X5 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* X5 S19)))
 (= X10 (+ (* X5 S18) (* X9 S19)))
 (= X10 (- (* X5 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X5 S19)))
 (= X10 (+ (* X6 S18) S19))
 (= X10 (- (* X6 S18) S19))
 (= X10 (- S18 (* X6 S19)))
 (= X10 (+ (* X6 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* X6 S19)))
 (= X10 (+ (* X6 S18) (* X7 S19)))
 (= X10 (- (* X6 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* X6 S19)))
 (= X10 (+ (* X6 S18) (* X8 S19)))
 (= X10 (- (* X6 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* X6 S19)))
 (= X10 (+ (* X6 S18) (* X9 S19)))
 (= X10 (- (* X6 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X6 S19)))
 (= X10 (+ (* X7 S18) S19))
 (= X10 (- (* X7 S18) S19))
 (= X10 (- S18 (* X7 S19)))
 (= X10 (+ (* X7 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* X7 S19)))
 (= X10 (+ (* X7 S18) (* X8 S19)))
 (= X10 (- (* X7 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* X7 S19)))
 (= X10 (+ (* X7 S18) (* X9 S19)))
 (= X10 (- (* X7 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X7 S19)))
 (= X10 (+ (* X8 S18) S19))
 (= X10 (- (* X8 S18) S19))
 (= X10 (- S18 (* X8 S19)))
 (= X10 (+ (* X8 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* X8 S19)))
 (= X10 (+ (* X8 S18) (* X9 S19)))
 (= X10 (- (* X8 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X8 S19)))
 (= X10 (+ (* X9 S18) S19))
 (= X10 (- (* X9 S18) S19))
 (= X10 (- S18 (* X9 S19)))
 (= X10 (+ (* X9 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* X9 S19)))
))
(assert (and (> X10 0) (< X10 1024) (power2 S18) (power2 S19)))
(assert (or
 (= X2 245)
 (= X3 245)
 (= X4 245)
 (= X5 245)
 (= X6 245)
 (= X7 245)
 (= X8 245)
 (= X9 245)
 (= X10 245)
))
(assert (or
 (= X2 73)
 (= X3 73)
 (= X4 73)
 (= X5 73)
 (= X6 73)
 (= X7 73)
 (= X8 73)
 (= X9 73)
 (= X10 73)
))
(assert (or
 (= X2 413)
 (= X3 413)
 (= X4 413)
 (= X5 413)
 (= X6 413)
 (= X7 413)
 (= X8 413)
 (= X9 413)
 (= X10 413)
))
(assert (or
 (= X2 253)
 (= X3 253)
 (= X4 253)
 (= X5 253)
 (= X6 253)
 (= X7 253)
 (= X8 253)
 (= X9 253)
 (= X10 253)
))
(assert (or
 (= X2 267)
 (= X3 267)
 (= X4 267)
 (= X5 267)
 (= X6 267)
 (= X7 267)
 (= X8 267)
 (= X9 267)
 (= X10 267)
))
(assert (or
 (= X2 81)
 (= X3 81)
 (= X4 81)
 (= X5 81)
 (= X6 81)
 (= X7 81)
 (= X8 81)
 (= X9 81)
 (= X10 81)
))
(assert (or
 (= X2 103)
 (= X3 103)
 (= X4 103)
 (= X5 103)
 (= X6 103)
 (= X7 103)
 (= X8 103)
 (= X9 103)
 (= X10 103)
))
(assert (or
 (= X2 395)
 (= X3 395)
 (= X4 395)
 (= X5 395)
 (= X6 395)
 (= X7 395)
 (= X8 395)
 (= X9 395)
 (= X10 395)
))
(assert (or
 (= X2 429)
 (= X3 429)
 (= X4 429)
 (= X5 429)
 (= X6 429)
 (= X7 429)
 (= X8 429)
 (= X9 429)
 (= X10 429)
))
(check-sat)
(exit)
