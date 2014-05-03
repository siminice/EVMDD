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
(define-fun power2 ((x Int)) Bool
  (or (= x 2048) (= x 1024) (= x 512) (= x 256) (= x 128) (= x 64) (= x 32) (= x 16) (= x 8) (= x 4) (= x 2) (= x 1)))
(assert (or
 (= X1 (+ S0 S1))
 (= X1 (- S0 S1))
 (= X1 (+ (* 17 S0) S1))
 (= X1 (- (* 17 S0) S1))
 (= X1 (- S0 (* 17 S1)))
 (= X1 (+ (* 17 S0) (* 17 S1)))
 (= X1 (- (* 17 S0) (* 17 S1)))
))
(assert (and (> X1 0) (< X1 4096) (power2 S0) (power2 S1)))
(assert (or
 (= X2 (+ S2 S3))
 (= X2 (- S2 S3))
 (= X2 (+ (* 17 S2) S3))
 (= X2 (- (* 17 S2) S3))
 (= X2 (- S2 (* 17 S3)))
 (= X2 (+ (* 17 S2) (* 17 S3)))
 (= X2 (- (* 17 S2) (* 17 S3)))
 (= X2 (+ (* 17 S2) (* X1 S3)))
 (= X2 (- (* 17 S2) (* X1 S3)))
 (= X2 (- (* X1 S2) (* 17 S3)))
 (= X2 (+ (* X1 S2) S3))
 (= X2 (- (* X1 S2) S3))
 (= X2 (- S2 (* X1 S3)))
 (= X2 (+ (* X1 S2) (* X1 S3)))
 (= X2 (- (* X1 S2) (* X1 S3)))
))
(assert (and (> X2 0) (< X2 4096) (power2 S2) (power2 S3)))
(assert (or
 (= X3 (+ (* 17 S4) S5))
 (= X3 (- (* 17 S4) S5))
 (= X3 (- S4 (* 17 S5)))
 (= X3 (+ (* 17 S4) (* 17 S5)))
 (= X3 (- (* 17 S4) (* 17 S5)))
 (= X3 (+ (* 17 S4) (* X1 S5)))
 (= X3 (- (* 17 S4) (* X1 S5)))
 (= X3 (- (* X1 S4) (* 17 S5)))
 (= X3 (+ (* 17 S4) (* X2 S5)))
 (= X3 (- (* 17 S4) (* X2 S5)))
 (= X3 (- (* X2 S4) (* 17 S5)))
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
(assert (and (> X3 0) (< X3 4096) (power2 S4) (power2 S5)))
(assert (or
 (= X4 (+ (* 17 S6) S7))
 (= X4 (- (* 17 S6) S7))
 (= X4 (- S6 (* 17 S7)))
 (= X4 (+ (* 17 S6) (* 17 S7)))
 (= X4 (- (* 17 S6) (* 17 S7)))
 (= X4 (+ (* 17 S6) (* X1 S7)))
 (= X4 (- (* 17 S6) (* X1 S7)))
 (= X4 (- (* X1 S6) (* 17 S7)))
 (= X4 (+ (* 17 S6) (* X2 S7)))
 (= X4 (- (* 17 S6) (* X2 S7)))
 (= X4 (- (* X2 S6) (* 17 S7)))
 (= X4 (+ (* 17 S6) (* X3 S7)))
 (= X4 (- (* 17 S6) (* X3 S7)))
 (= X4 (- (* X3 S6) (* 17 S7)))
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
(assert (and (> X4 0) (< X4 4096) (power2 S6) (power2 S7)))
(assert (or
 (= X5 (+ (* 17 S8) S9))
 (= X5 (- (* 17 S8) S9))
 (= X5 (- S8 (* 17 S9)))
 (= X5 (+ (* 17 S8) (* 17 S9)))
 (= X5 (- (* 17 S8) (* 17 S9)))
 (= X5 (+ (* 17 S8) (* X1 S9)))
 (= X5 (- (* 17 S8) (* X1 S9)))
 (= X5 (- (* X1 S8) (* 17 S9)))
 (= X5 (+ (* 17 S8) (* X2 S9)))
 (= X5 (- (* 17 S8) (* X2 S9)))
 (= X5 (- (* X2 S8) (* 17 S9)))
 (= X5 (+ (* 17 S8) (* X3 S9)))
 (= X5 (- (* 17 S8) (* X3 S9)))
 (= X5 (- (* X3 S8) (* 17 S9)))
 (= X5 (+ (* 17 S8) (* X4 S9)))
 (= X5 (- (* 17 S8) (* X4 S9)))
 (= X5 (- (* X4 S8) (* 17 S9)))
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
(assert (and (> X5 0) (< X5 4096) (power2 S8) (power2 S9)))
(assert (or
 (= X6 (+ (* 17 S10) S11))
 (= X6 (- (* 17 S10) S11))
 (= X6 (- S10 (* 17 S11)))
 (= X6 (+ (* 17 S10) (* 17 S11)))
 (= X6 (- (* 17 S10) (* 17 S11)))
 (= X6 (+ (* 17 S10) (* X1 S11)))
 (= X6 (- (* 17 S10) (* X1 S11)))
 (= X6 (- (* X1 S10) (* 17 S11)))
 (= X6 (+ (* 17 S10) (* X2 S11)))
 (= X6 (- (* 17 S10) (* X2 S11)))
 (= X6 (- (* X2 S10) (* 17 S11)))
 (= X6 (+ (* 17 S10) (* X3 S11)))
 (= X6 (- (* 17 S10) (* X3 S11)))
 (= X6 (- (* X3 S10) (* 17 S11)))
 (= X6 (+ (* 17 S10) (* X4 S11)))
 (= X6 (- (* 17 S10) (* X4 S11)))
 (= X6 (- (* X4 S10) (* 17 S11)))
 (= X6 (+ (* 17 S10) (* X5 S11)))
 (= X6 (- (* 17 S10) (* X5 S11)))
 (= X6 (- (* X5 S10) (* 17 S11)))
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
(assert (and (> X6 0) (< X6 4096) (power2 S10) (power2 S11)))
(assert (or
 (= X7 (+ (* 17 S12) S13))
 (= X7 (- (* 17 S12) S13))
 (= X7 (- S12 (* 17 S13)))
 (= X7 (+ (* 17 S12) (* 17 S13)))
 (= X7 (- (* 17 S12) (* 17 S13)))
 (= X7 (+ (* 17 S12) (* X1 S13)))
 (= X7 (- (* 17 S12) (* X1 S13)))
 (= X7 (- (* X1 S12) (* 17 S13)))
 (= X7 (+ (* 17 S12) (* X2 S13)))
 (= X7 (- (* 17 S12) (* X2 S13)))
 (= X7 (- (* X2 S12) (* 17 S13)))
 (= X7 (+ (* 17 S12) (* X3 S13)))
 (= X7 (- (* 17 S12) (* X3 S13)))
 (= X7 (- (* X3 S12) (* 17 S13)))
 (= X7 (+ (* 17 S12) (* X4 S13)))
 (= X7 (- (* 17 S12) (* X4 S13)))
 (= X7 (- (* X4 S12) (* 17 S13)))
 (= X7 (+ (* 17 S12) (* X5 S13)))
 (= X7 (- (* 17 S12) (* X5 S13)))
 (= X7 (- (* X5 S12) (* 17 S13)))
 (= X7 (+ (* 17 S12) (* X6 S13)))
 (= X7 (- (* 17 S12) (* X6 S13)))
 (= X7 (- (* X6 S12) (* 17 S13)))
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
(assert (and (> X7 0) (< X7 4096) (power2 S12) (power2 S13)))
(assert (or
 (= X8 (+ (* 17 S14) S15))
 (= X8 (- (* 17 S14) S15))
 (= X8 (- S14 (* 17 S15)))
 (= X8 (+ (* 17 S14) (* 17 S15)))
 (= X8 (- (* 17 S14) (* 17 S15)))
 (= X8 (+ (* 17 S14) (* X1 S15)))
 (= X8 (- (* 17 S14) (* X1 S15)))
 (= X8 (- (* X1 S14) (* 17 S15)))
 (= X8 (+ (* 17 S14) (* X2 S15)))
 (= X8 (- (* 17 S14) (* X2 S15)))
 (= X8 (- (* X2 S14) (* 17 S15)))
 (= X8 (+ (* 17 S14) (* X3 S15)))
 (= X8 (- (* 17 S14) (* X3 S15)))
 (= X8 (- (* X3 S14) (* 17 S15)))
 (= X8 (+ (* 17 S14) (* X4 S15)))
 (= X8 (- (* 17 S14) (* X4 S15)))
 (= X8 (- (* X4 S14) (* 17 S15)))
 (= X8 (+ (* 17 S14) (* X5 S15)))
 (= X8 (- (* 17 S14) (* X5 S15)))
 (= X8 (- (* X5 S14) (* 17 S15)))
 (= X8 (+ (* 17 S14) (* X6 S15)))
 (= X8 (- (* 17 S14) (* X6 S15)))
 (= X8 (- (* X6 S14) (* 17 S15)))
 (= X8 (+ (* 17 S14) (* X7 S15)))
 (= X8 (- (* 17 S14) (* X7 S15)))
 (= X8 (- (* X7 S14) (* 17 S15)))
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
(assert (and (> X8 0) (< X8 4096) (power2 S14) (power2 S15)))
(assert (or
 (= X9 (+ (* 17 S16) S17))
 (= X9 (- (* 17 S16) S17))
 (= X9 (- S16 (* 17 S17)))
 (= X9 (+ (* 17 S16) (* 17 S17)))
 (= X9 (- (* 17 S16) (* 17 S17)))
 (= X9 (+ (* 17 S16) (* X1 S17)))
 (= X9 (- (* 17 S16) (* X1 S17)))
 (= X9 (- (* X1 S16) (* 17 S17)))
 (= X9 (+ (* 17 S16) (* X2 S17)))
 (= X9 (- (* 17 S16) (* X2 S17)))
 (= X9 (- (* X2 S16) (* 17 S17)))
 (= X9 (+ (* 17 S16) (* X3 S17)))
 (= X9 (- (* 17 S16) (* X3 S17)))
 (= X9 (- (* X3 S16) (* 17 S17)))
 (= X9 (+ (* 17 S16) (* X4 S17)))
 (= X9 (- (* 17 S16) (* X4 S17)))
 (= X9 (- (* X4 S16) (* 17 S17)))
 (= X9 (+ (* 17 S16) (* X5 S17)))
 (= X9 (- (* 17 S16) (* X5 S17)))
 (= X9 (- (* X5 S16) (* 17 S17)))
 (= X9 (+ (* 17 S16) (* X6 S17)))
 (= X9 (- (* 17 S16) (* X6 S17)))
 (= X9 (- (* X6 S16) (* 17 S17)))
 (= X9 (+ (* 17 S16) (* X7 S17)))
 (= X9 (- (* 17 S16) (* X7 S17)))
 (= X9 (- (* X7 S16) (* 17 S17)))
 (= X9 (+ (* 17 S16) (* X8 S17)))
 (= X9 (- (* 17 S16) (* X8 S17)))
 (= X9 (- (* X8 S16) (* 17 S17)))
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
(assert (and (> X9 0) (< X9 4096) (power2 S16) (power2 S17)))
(assert (or
 (= X10 (+ (* 17 S18) S19))
 (= X10 (- (* 17 S18) S19))
 (= X10 (- S18 (* 17 S19)))
 (= X10 (+ (* 17 S18) (* 17 S19)))
 (= X10 (- (* 17 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X1 S19)))
 (= X10 (- (* 17 S18) (* X1 S19)))
 (= X10 (- (* X1 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X2 S19)))
 (= X10 (- (* 17 S18) (* X2 S19)))
 (= X10 (- (* X2 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X3 S19)))
 (= X10 (- (* 17 S18) (* X3 S19)))
 (= X10 (- (* X3 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X4 S19)))
 (= X10 (- (* 17 S18) (* X4 S19)))
 (= X10 (- (* X4 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X5 S19)))
 (= X10 (- (* 17 S18) (* X5 S19)))
 (= X10 (- (* X5 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X6 S19)))
 (= X10 (- (* 17 S18) (* X6 S19)))
 (= X10 (- (* X6 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X7 S19)))
 (= X10 (- (* 17 S18) (* X7 S19)))
 (= X10 (- (* X7 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X8 S19)))
 (= X10 (- (* 17 S18) (* X8 S19)))
 (= X10 (- (* X8 S18) (* 17 S19)))
 (= X10 (+ (* 17 S18) (* X9 S19)))
 (= X10 (- (* 17 S18) (* X9 S19)))
 (= X10 (- (* X9 S18) (* 17 S19)))
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
(assert (and (> X10 0) (< X10 4096) (power2 S18) (power2 S19)))
(assert (or
 (= X11 (+ (* 17 S20) S21))
 (= X11 (- (* 17 S20) S21))
 (= X11 (- S20 (* 17 S21)))
 (= X11 (+ (* 17 S20) (* 17 S21)))
 (= X11 (- (* 17 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X1 S21)))
 (= X11 (- (* 17 S20) (* X1 S21)))
 (= X11 (- (* X1 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X2 S21)))
 (= X11 (- (* 17 S20) (* X2 S21)))
 (= X11 (- (* X2 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X3 S21)))
 (= X11 (- (* 17 S20) (* X3 S21)))
 (= X11 (- (* X3 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X4 S21)))
 (= X11 (- (* 17 S20) (* X4 S21)))
 (= X11 (- (* X4 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X5 S21)))
 (= X11 (- (* 17 S20) (* X5 S21)))
 (= X11 (- (* X5 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X6 S21)))
 (= X11 (- (* 17 S20) (* X6 S21)))
 (= X11 (- (* X6 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X7 S21)))
 (= X11 (- (* 17 S20) (* X7 S21)))
 (= X11 (- (* X7 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X8 S21)))
 (= X11 (- (* 17 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X9 S21)))
 (= X11 (- (* 17 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* 17 S21)))
 (= X11 (+ (* 17 S20) (* X10 S21)))
 (= X11 (- (* 17 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* 17 S21)))
 (= X11 (+ (* X1 S20) S21))
 (= X11 (- (* X1 S20) S21))
 (= X11 (- S20 (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X1 S21)))
 (= X11 (- (* X1 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X2 S21)))
 (= X11 (- (* X1 S20) (* X2 S21)))
 (= X11 (- (* X2 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X3 S21)))
 (= X11 (- (* X1 S20) (* X3 S21)))
 (= X11 (- (* X3 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X4 S21)))
 (= X11 (- (* X1 S20) (* X4 S21)))
 (= X11 (- (* X4 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X5 S21)))
 (= X11 (- (* X1 S20) (* X5 S21)))
 (= X11 (- (* X5 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X6 S21)))
 (= X11 (- (* X1 S20) (* X6 S21)))
 (= X11 (- (* X6 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X7 S21)))
 (= X11 (- (* X1 S20) (* X7 S21)))
 (= X11 (- (* X7 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X8 S21)))
 (= X11 (- (* X1 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X9 S21)))
 (= X11 (- (* X1 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X1 S21)))
 (= X11 (+ (* X1 S20) (* X10 S21)))
 (= X11 (- (* X1 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X1 S21)))
 (= X11 (+ (* X2 S20) S21))
 (= X11 (- (* X2 S20) S21))
 (= X11 (- S20 (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X2 S21)))
 (= X11 (- (* X2 S20) (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X3 S21)))
 (= X11 (- (* X2 S20) (* X3 S21)))
 (= X11 (- (* X3 S20) (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X4 S21)))
 (= X11 (- (* X2 S20) (* X4 S21)))
 (= X11 (- (* X4 S20) (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X5 S21)))
 (= X11 (- (* X2 S20) (* X5 S21)))
 (= X11 (- (* X5 S20) (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X6 S21)))
 (= X11 (- (* X2 S20) (* X6 S21)))
 (= X11 (- (* X6 S20) (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X7 S21)))
 (= X11 (- (* X2 S20) (* X7 S21)))
 (= X11 (- (* X7 S20) (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X8 S21)))
 (= X11 (- (* X2 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X9 S21)))
 (= X11 (- (* X2 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X2 S21)))
 (= X11 (+ (* X2 S20) (* X10 S21)))
 (= X11 (- (* X2 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X2 S21)))
 (= X11 (+ (* X3 S20) S21))
 (= X11 (- (* X3 S20) S21))
 (= X11 (- S20 (* X3 S21)))
 (= X11 (+ (* X3 S20) (* X3 S21)))
 (= X11 (- (* X3 S20) (* X3 S21)))
 (= X11 (+ (* X3 S20) (* X4 S21)))
 (= X11 (- (* X3 S20) (* X4 S21)))
 (= X11 (- (* X4 S20) (* X3 S21)))
 (= X11 (+ (* X3 S20) (* X5 S21)))
 (= X11 (- (* X3 S20) (* X5 S21)))
 (= X11 (- (* X5 S20) (* X3 S21)))
 (= X11 (+ (* X3 S20) (* X6 S21)))
 (= X11 (- (* X3 S20) (* X6 S21)))
 (= X11 (- (* X6 S20) (* X3 S21)))
 (= X11 (+ (* X3 S20) (* X7 S21)))
 (= X11 (- (* X3 S20) (* X7 S21)))
 (= X11 (- (* X7 S20) (* X3 S21)))
 (= X11 (+ (* X3 S20) (* X8 S21)))
 (= X11 (- (* X3 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* X3 S21)))
 (= X11 (+ (* X3 S20) (* X9 S21)))
 (= X11 (- (* X3 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X3 S21)))
 (= X11 (+ (* X3 S20) (* X10 S21)))
 (= X11 (- (* X3 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X3 S21)))
 (= X11 (+ (* X4 S20) S21))
 (= X11 (- (* X4 S20) S21))
 (= X11 (- S20 (* X4 S21)))
 (= X11 (+ (* X4 S20) (* X4 S21)))
 (= X11 (- (* X4 S20) (* X4 S21)))
 (= X11 (+ (* X4 S20) (* X5 S21)))
 (= X11 (- (* X4 S20) (* X5 S21)))
 (= X11 (- (* X5 S20) (* X4 S21)))
 (= X11 (+ (* X4 S20) (* X6 S21)))
 (= X11 (- (* X4 S20) (* X6 S21)))
 (= X11 (- (* X6 S20) (* X4 S21)))
 (= X11 (+ (* X4 S20) (* X7 S21)))
 (= X11 (- (* X4 S20) (* X7 S21)))
 (= X11 (- (* X7 S20) (* X4 S21)))
 (= X11 (+ (* X4 S20) (* X8 S21)))
 (= X11 (- (* X4 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* X4 S21)))
 (= X11 (+ (* X4 S20) (* X9 S21)))
 (= X11 (- (* X4 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X4 S21)))
 (= X11 (+ (* X4 S20) (* X10 S21)))
 (= X11 (- (* X4 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X4 S21)))
 (= X11 (+ (* X5 S20) S21))
 (= X11 (- (* X5 S20) S21))
 (= X11 (- S20 (* X5 S21)))
 (= X11 (+ (* X5 S20) (* X5 S21)))
 (= X11 (- (* X5 S20) (* X5 S21)))
 (= X11 (+ (* X5 S20) (* X6 S21)))
 (= X11 (- (* X5 S20) (* X6 S21)))
 (= X11 (- (* X6 S20) (* X5 S21)))
 (= X11 (+ (* X5 S20) (* X7 S21)))
 (= X11 (- (* X5 S20) (* X7 S21)))
 (= X11 (- (* X7 S20) (* X5 S21)))
 (= X11 (+ (* X5 S20) (* X8 S21)))
 (= X11 (- (* X5 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* X5 S21)))
 (= X11 (+ (* X5 S20) (* X9 S21)))
 (= X11 (- (* X5 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X5 S21)))
 (= X11 (+ (* X5 S20) (* X10 S21)))
 (= X11 (- (* X5 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X5 S21)))
 (= X11 (+ (* X6 S20) S21))
 (= X11 (- (* X6 S20) S21))
 (= X11 (- S20 (* X6 S21)))
 (= X11 (+ (* X6 S20) (* X6 S21)))
 (= X11 (- (* X6 S20) (* X6 S21)))
 (= X11 (+ (* X6 S20) (* X7 S21)))
 (= X11 (- (* X6 S20) (* X7 S21)))
 (= X11 (- (* X7 S20) (* X6 S21)))
 (= X11 (+ (* X6 S20) (* X8 S21)))
 (= X11 (- (* X6 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* X6 S21)))
 (= X11 (+ (* X6 S20) (* X9 S21)))
 (= X11 (- (* X6 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X6 S21)))
 (= X11 (+ (* X6 S20) (* X10 S21)))
 (= X11 (- (* X6 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X6 S21)))
 (= X11 (+ (* X7 S20) S21))
 (= X11 (- (* X7 S20) S21))
 (= X11 (- S20 (* X7 S21)))
 (= X11 (+ (* X7 S20) (* X7 S21)))
 (= X11 (- (* X7 S20) (* X7 S21)))
 (= X11 (+ (* X7 S20) (* X8 S21)))
 (= X11 (- (* X7 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* X7 S21)))
 (= X11 (+ (* X7 S20) (* X9 S21)))
 (= X11 (- (* X7 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X7 S21)))
 (= X11 (+ (* X7 S20) (* X10 S21)))
 (= X11 (- (* X7 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X7 S21)))
 (= X11 (+ (* X8 S20) S21))
 (= X11 (- (* X8 S20) S21))
 (= X11 (- S20 (* X8 S21)))
 (= X11 (+ (* X8 S20) (* X8 S21)))
 (= X11 (- (* X8 S20) (* X8 S21)))
 (= X11 (+ (* X8 S20) (* X9 S21)))
 (= X11 (- (* X8 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X8 S21)))
 (= X11 (+ (* X8 S20) (* X10 S21)))
 (= X11 (- (* X8 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X8 S21)))
 (= X11 (+ (* X9 S20) S21))
 (= X11 (- (* X9 S20) S21))
 (= X11 (- S20 (* X9 S21)))
 (= X11 (+ (* X9 S20) (* X9 S21)))
 (= X11 (- (* X9 S20) (* X9 S21)))
 (= X11 (+ (* X9 S20) (* X10 S21)))
 (= X11 (- (* X9 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X9 S21)))
 (= X11 (+ (* X10 S20) S21))
 (= X11 (- (* X10 S20) S21))
 (= X11 (- S20 (* X10 S21)))
 (= X11 (+ (* X10 S20) (* X10 S21)))
 (= X11 (- (* X10 S20) (* X10 S21)))
))
(assert (and (> X11 0) (< X11 4096) (power2 S20) (power2 S21)))
(assert (or
 (= X2 59)
 (= X3 59)
 (= X4 59)
 (= X5 59)
 (= X6 59)
 (= X7 59)
 (= X8 59)
 (= X9 59)
 (= X10 59)
 (= X11 59)
))
(assert (or
 (= X2 473)
 (= X3 473)
 (= X4 473)
 (= X5 473)
 (= X6 473)
 (= X7 473)
 (= X8 473)
 (= X9 473)
 (= X10 473)
 (= X11 473)
))
(assert (or
 (= X2 181)
 (= X3 181)
 (= X4 181)
 (= X5 181)
 (= X6 181)
 (= X7 181)
 (= X8 181)
 (= X9 181)
 (= X10 181)
 (= X11 181)
))
(assert (or
 (= X2 555)
 (= X3 555)
 (= X4 555)
 (= X5 555)
 (= X6 555)
 (= X7 555)
 (= X8 555)
 (= X9 555)
 (= X10 555)
 (= X11 555)
))
(assert (or
 (= X2 1261)
 (= X3 1261)
 (= X4 1261)
 (= X5 1261)
 (= X6 1261)
 (= X7 1261)
 (= X8 1261)
 (= X9 1261)
 (= X10 1261)
 (= X11 1261)
))
(assert (or
 (= X2 391)
 (= X3 391)
 (= X4 391)
 (= X5 391)
 (= X6 391)
 (= X7 391)
 (= X8 391)
 (= X9 391)
 (= X10 391)
 (= X11 391)
))
(assert (or
 (= X2 599)
 (= X3 599)
 (= X4 599)
 (= X5 599)
 (= X6 599)
 (= X7 599)
 (= X8 599)
 (= X9 599)
 (= X10 599)
 (= X11 599)
))
(assert (or
 (= X2 1959)
 (= X3 1959)
 (= X4 1959)
 (= X5 1959)
 (= X6 1959)
 (= X7 1959)
 (= X8 1959)
 (= X9 1959)
 (= X10 1959)
 (= X11 1959)
))
(assert (or
 (= X2 1401)
 (= X3 1401)
 (= X4 1401)
 (= X5 1401)
 (= X6 1401)
 (= X7 1401)
 (= X8 1401)
 (= X9 1401)
 (= X10 1401)
 (= X11 1401)
))
(check-sat)
(exit)
