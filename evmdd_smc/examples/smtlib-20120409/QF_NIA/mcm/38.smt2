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
  (or (= x 1024) (= x 512) (= x 256) (= x 128) (= x 64) (= x 32) (= x 16) (= x 8) (= x 4) (= x 2) (= x 1)))
(assert (or
 (= X1 (+ S0 S1))
 (= X1 (- S0 S1))
 (= X1 (+ (* 255 S0) S1))
 (= X1 (- (* 255 S0) S1))
 (= X1 (- S0 (* 255 S1)))
 (= X1 (+ (* 255 S0) (* 255 S1)))
 (= X1 (- (* 255 S0) (* 255 S1)))
))
(assert (and (> X1 0) (< X1 2048) (power2 S0) (power2 S1)))
(assert (or
 (= X2 (+ (* 255 S2) S3))
 (= X2 (- (* 255 S2) S3))
 (= X2 (- S2 (* 255 S3)))
 (= X2 (+ (* 255 S2) (* 255 S3)))
 (= X2 (- (* 255 S2) (* 255 S3)))
 (= X2 (+ (* 255 S2) (* X1 S3)))
 (= X2 (- (* 255 S2) (* X1 S3)))
 (= X2 (- (* X1 S2) (* 255 S3)))
 (= X2 (+ (* X1 S2) S3))
 (= X2 (- (* X1 S2) S3))
 (= X2 (- S2 (* X1 S3)))
 (= X2 (+ (* X1 S2) (* X1 S3)))
 (= X2 (- (* X1 S2) (* X1 S3)))
))
(assert (and (> X2 0) (< X2 2048) (power2 S2) (power2 S3)))
(assert (or
 (= X3 (+ (* 255 S4) S5))
 (= X3 (- (* 255 S4) S5))
 (= X3 (- S4 (* 255 S5)))
 (= X3 (+ (* 255 S4) (* 255 S5)))
 (= X3 (- (* 255 S4) (* 255 S5)))
 (= X3 (+ (* 255 S4) (* X1 S5)))
 (= X3 (- (* 255 S4) (* X1 S5)))
 (= X3 (- (* X1 S4) (* 255 S5)))
 (= X3 (+ (* 255 S4) (* X2 S5)))
 (= X3 (- (* 255 S4) (* X2 S5)))
 (= X3 (- (* X2 S4) (* 255 S5)))
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
(assert (and (> X3 0) (< X3 2048) (power2 S4) (power2 S5)))
(assert (or
 (= X4 (+ (* 255 S6) S7))
 (= X4 (- (* 255 S6) S7))
 (= X4 (- S6 (* 255 S7)))
 (= X4 (+ (* 255 S6) (* 255 S7)))
 (= X4 (- (* 255 S6) (* 255 S7)))
 (= X4 (+ (* 255 S6) (* X1 S7)))
 (= X4 (- (* 255 S6) (* X1 S7)))
 (= X4 (- (* X1 S6) (* 255 S7)))
 (= X4 (+ (* 255 S6) (* X2 S7)))
 (= X4 (- (* 255 S6) (* X2 S7)))
 (= X4 (- (* X2 S6) (* 255 S7)))
 (= X4 (+ (* 255 S6) (* X3 S7)))
 (= X4 (- (* 255 S6) (* X3 S7)))
 (= X4 (- (* X3 S6) (* 255 S7)))
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
(assert (and (> X4 0) (< X4 2048) (power2 S6) (power2 S7)))
(assert (or
 (= X5 (+ (* 255 S8) S9))
 (= X5 (- (* 255 S8) S9))
 (= X5 (- S8 (* 255 S9)))
 (= X5 (+ (* 255 S8) (* 255 S9)))
 (= X5 (- (* 255 S8) (* 255 S9)))
 (= X5 (+ (* 255 S8) (* X1 S9)))
 (= X5 (- (* 255 S8) (* X1 S9)))
 (= X5 (- (* X1 S8) (* 255 S9)))
 (= X5 (+ (* 255 S8) (* X2 S9)))
 (= X5 (- (* 255 S8) (* X2 S9)))
 (= X5 (- (* X2 S8) (* 255 S9)))
 (= X5 (+ (* 255 S8) (* X3 S9)))
 (= X5 (- (* 255 S8) (* X3 S9)))
 (= X5 (- (* X3 S8) (* 255 S9)))
 (= X5 (+ (* 255 S8) (* X4 S9)))
 (= X5 (- (* 255 S8) (* X4 S9)))
 (= X5 (- (* X4 S8) (* 255 S9)))
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
(assert (and (> X5 0) (< X5 2048) (power2 S8) (power2 S9)))
(assert (or
 (= X6 (+ (* 255 S10) S11))
 (= X6 (- (* 255 S10) S11))
 (= X6 (- S10 (* 255 S11)))
 (= X6 (+ (* 255 S10) (* 255 S11)))
 (= X6 (- (* 255 S10) (* 255 S11)))
 (= X6 (+ (* 255 S10) (* X1 S11)))
 (= X6 (- (* 255 S10) (* X1 S11)))
 (= X6 (- (* X1 S10) (* 255 S11)))
 (= X6 (+ (* 255 S10) (* X2 S11)))
 (= X6 (- (* 255 S10) (* X2 S11)))
 (= X6 (- (* X2 S10) (* 255 S11)))
 (= X6 (+ (* 255 S10) (* X3 S11)))
 (= X6 (- (* 255 S10) (* X3 S11)))
 (= X6 (- (* X3 S10) (* 255 S11)))
 (= X6 (+ (* 255 S10) (* X4 S11)))
 (= X6 (- (* 255 S10) (* X4 S11)))
 (= X6 (- (* X4 S10) (* 255 S11)))
 (= X6 (+ (* 255 S10) (* X5 S11)))
 (= X6 (- (* 255 S10) (* X5 S11)))
 (= X6 (- (* X5 S10) (* 255 S11)))
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
(assert (and (> X6 0) (< X6 2048) (power2 S10) (power2 S11)))
(assert (or
 (= X7 (+ (* 255 S12) S13))
 (= X7 (- (* 255 S12) S13))
 (= X7 (- S12 (* 255 S13)))
 (= X7 (+ (* 255 S12) (* 255 S13)))
 (= X7 (- (* 255 S12) (* 255 S13)))
 (= X7 (+ (* 255 S12) (* X1 S13)))
 (= X7 (- (* 255 S12) (* X1 S13)))
 (= X7 (- (* X1 S12) (* 255 S13)))
 (= X7 (+ (* 255 S12) (* X2 S13)))
 (= X7 (- (* 255 S12) (* X2 S13)))
 (= X7 (- (* X2 S12) (* 255 S13)))
 (= X7 (+ (* 255 S12) (* X3 S13)))
 (= X7 (- (* 255 S12) (* X3 S13)))
 (= X7 (- (* X3 S12) (* 255 S13)))
 (= X7 (+ (* 255 S12) (* X4 S13)))
 (= X7 (- (* 255 S12) (* X4 S13)))
 (= X7 (- (* X4 S12) (* 255 S13)))
 (= X7 (+ (* 255 S12) (* X5 S13)))
 (= X7 (- (* 255 S12) (* X5 S13)))
 (= X7 (- (* X5 S12) (* 255 S13)))
 (= X7 (+ (* 255 S12) (* X6 S13)))
 (= X7 (- (* 255 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* 255 S13)))
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
(assert (and (> X7 0) (< X7 2048) (power2 S12) (power2 S13)))
(assert (or
 (= X8 (+ (* 255 S14) S15))
 (= X8 (- (* 255 S14) S15))
 (= X8 (- S14 (* 255 S15)))
 (= X8 (+ (* 255 S14) (* 255 S15)))
 (= X8 (- (* 255 S14) (* 255 S15)))
 (= X8 (+ (* 255 S14) (* X1 S15)))
 (= X8 (- (* 255 S14) (* X1 S15)))
 (= X8 (- (* X1 S14) (* 255 S15)))
 (= X8 (+ (* 255 S14) (* X2 S15)))
 (= X8 (- (* 255 S14) (* X2 S15)))
 (= X8 (- (* X2 S14) (* 255 S15)))
 (= X8 (+ (* 255 S14) (* X3 S15)))
 (= X8 (- (* 255 S14) (* X3 S15)))
 (= X8 (- (* X3 S14) (* 255 S15)))
 (= X8 (+ (* 255 S14) (* X4 S15)))
 (= X8 (- (* 255 S14) (* X4 S15)))
 (= X8 (- (* X4 S14) (* 255 S15)))
 (= X8 (+ (* 255 S14) (* X5 S15)))
 (= X8 (- (* 255 S14) (* X5 S15)))
 (= X8 (- (* X5 S14) (* 255 S15)))
 (= X8 (+ (* 255 S14) (* X6 S15)))
 (= X8 (- (* 255 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* 255 S15)))
 (= X8 (+ (* 255 S14) (* X7 S15)))
 (= X8 (- (* 255 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* 255 S15)))
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
(assert (and (> X8 0) (< X8 2048) (power2 S14) (power2 S15)))
(assert (or
 (= X9 (+ (* 255 S16) S17))
 (= X9 (- (* 255 S16) S17))
 (= X9 (- S16 (* 255 S17)))
 (= X9 (+ (* 255 S16) (* 255 S17)))
 (= X9 (- (* 255 S16) (* 255 S17)))
 (= X9 (+ (* 255 S16) (* X1 S17)))
 (= X9 (- (* 255 S16) (* X1 S17)))
 (= X9 (- (* X1 S16) (* 255 S17)))
 (= X9 (+ (* 255 S16) (* X2 S17)))
 (= X9 (- (* 255 S16) (* X2 S17)))
 (= X9 (- (* X2 S16) (* 255 S17)))
 (= X9 (+ (* 255 S16) (* X3 S17)))
 (= X9 (- (* 255 S16) (* X3 S17)))
 (= X9 (- (* X3 S16) (* 255 S17)))
 (= X9 (+ (* 255 S16) (* X4 S17)))
 (= X9 (- (* 255 S16) (* X4 S17)))
 (= X9 (- (* X4 S16) (* 255 S17)))
 (= X9 (+ (* 255 S16) (* X5 S17)))
 (= X9 (- (* 255 S16) (* X5 S17)))
 (= X9 (- (* X5 S16) (* 255 S17)))
 (= X9 (+ (* 255 S16) (* X6 S17)))
 (= X9 (- (* 255 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* 255 S17)))
 (= X9 (+ (* 255 S16) (* X7 S17)))
 (= X9 (- (* 255 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* 255 S17)))
 (= X9 (+ (* 255 S16) (* X8 S17)))
 (= X9 (- (* 255 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* 255 S17)))
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
(assert (and (> X9 0) (< X9 2048) (power2 S16) (power2 S17)))
(assert (or
 (= X10 (+ (* 255 S18) S19))
 (= X10 (- (* 255 S18) S19))
 (= X10 (- S18 (* 255 S19)))
 (= X10 (+ (* 255 S18) (* 255 S19)))
 (= X10 (- (* 255 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X1 S19)))
 (= X10 (- (* 255 S18) (* X1 S19)))
 (= X10 (- (* X1 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X2 S19)))
 (= X10 (- (* 255 S18) (* X2 S19)))
 (= X10 (- (* X2 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X3 S19)))
 (= X10 (- (* 255 S18) (* X3 S19)))
 (= X10 (- (* X3 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X4 S19)))
 (= X10 (- (* 255 S18) (* X4 S19)))
 (= X10 (- (* X4 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X5 S19)))
 (= X10 (- (* 255 S18) (* X5 S19)))
 (= X10 (- (* X5 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X6 S19)))
 (= X10 (- (* 255 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X7 S19)))
 (= X10 (- (* 255 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X8 S19)))
 (= X10 (- (* 255 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* 255 S19)))
 (= X10 (+ (* 255 S18) (* X9 S19)))
 (= X10 (- (* 255 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* 255 S19)))
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
(assert (and (> X10 0) (< X10 2048) (power2 S18) (power2 S19)))
(assert (or
 (= X2 483)
 (= X3 483)
 (= X4 483)
 (= X5 483)
 (= X6 483)
 (= X7 483)
 (= X8 483)
 (= X9 483)
 (= X10 483)
))
(assert (or
 (= X2 307)
 (= X3 307)
 (= X4 307)
 (= X5 307)
 (= X6 307)
 (= X7 307)
 (= X8 307)
 (= X9 307)
 (= X10 307)
))
(assert (or
 (= X2 85)
 (= X3 85)
 (= X4 85)
 (= X5 85)
 (= X6 85)
 (= X7 85)
 (= X8 85)
 (= X9 85)
 (= X10 85)
))
(assert (or
 (= X2 499)
 (= X3 499)
 (= X4 499)
 (= X5 499)
 (= X6 499)
 (= X7 499)
 (= X8 499)
 (= X9 499)
 (= X10 499)
))
(assert (or
 (= X2 1007)
 (= X3 1007)
 (= X4 1007)
 (= X5 1007)
 (= X6 1007)
 (= X7 1007)
 (= X8 1007)
 (= X9 1007)
 (= X10 1007)
))
(assert (or
 (= X2 361)
 (= X3 361)
 (= X4 361)
 (= X5 361)
 (= X6 361)
 (= X7 361)
 (= X8 361)
 (= X9 361)
 (= X10 361)
))
(assert (or
 (= X2 119)
 (= X3 119)
 (= X4 119)
 (= X5 119)
 (= X6 119)
 (= X7 119)
 (= X8 119)
 (= X9 119)
 (= X10 119)
))
(assert (or
 (= X2 653)
 (= X3 653)
 (= X4 653)
 (= X5 653)
 (= X6 653)
 (= X7 653)
 (= X8 653)
 (= X9 653)
 (= X10 653)
))
(assert (or
 (= X2 367)
 (= X3 367)
 (= X4 367)
 (= X5 367)
 (= X6 367)
 (= X7 367)
 (= X8 367)
 (= X9 367)
 (= X10 367)
))
(check-sat)
(exit)
