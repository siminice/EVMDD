(set-logic QF_NIA)
(set-info :source |
 more info in 'N. P. Lopes, L. Aksoy, V. Manquinho, J. Monteiro.
 Optimally Solving the MCM Problem Using Pseudo-Boolean Satisfiability.
 Technical Report RT/43/2010, INESC-ID, Nov. 2010'. |)
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
(define-fun power2 ((x Int)) Bool
  (or (= x 2048) (= x 1024) (= x 512) (= x 256) (= x 128) (= x 64) (= x 32) (= x 16) (= x 8) (= x 4) (= x 2) (= x 1)))
(assert (or
 (= X2 (+ S0 S1))
 (= X2 (- S0 S1))
 (= X2 (+ (* 65 S0) S1))
 (= X2 (- (* 65 S0) S1))
 (= X2 (- S0 (* 65 S1)))
 (= X2 (+ (* 65 S0) (* 65 S1)))
 (= X2 (- (* 65 S0) (* 65 S1)))
 (= X2 (+ (* 65 S0) (* 975 S1)))
 (= X2 (- (* 65 S0) (* 975 S1)))
 (= X2 (- (* 975 S0) (* 65 S1)))
 (= X2 (+ (* 975 S0) S1))
 (= X2 (- (* 975 S0) S1))
 (= X2 (- S0 (* 975 S1)))
 (= X2 (+ (* 975 S0) (* 975 S1)))
 (= X2 (- (* 975 S0) (* 975 S1)))
))
(assert (and (> X2 0) (< X2 4096) (power2 S0) (power2 S1)))
(assert (or
 (= X3 (+ (* 65 S2) S3))
 (= X3 (- (* 65 S2) S3))
 (= X3 (- S2 (* 65 S3)))
 (= X3 (+ (* 65 S2) (* 65 S3)))
 (= X3 (- (* 65 S2) (* 65 S3)))
 (= X3 (+ (* 65 S2) (* 975 S3)))
 (= X3 (- (* 65 S2) (* 975 S3)))
 (= X3 (- (* 975 S2) (* 65 S3)))
 (= X3 (+ (* 65 S2) (* X2 S3)))
 (= X3 (- (* 65 S2) (* X2 S3)))
 (= X3 (- (* X2 S2) (* 65 S3)))
 (= X3 (+ (* 975 S2) S3))
 (= X3 (- (* 975 S2) S3))
 (= X3 (- S2 (* 975 S3)))
 (= X3 (+ (* 975 S2) (* 975 S3)))
 (= X3 (- (* 975 S2) (* 975 S3)))
 (= X3 (+ (* 975 S2) (* X2 S3)))
 (= X3 (- (* 975 S2) (* X2 S3)))
 (= X3 (- (* X2 S2) (* 975 S3)))
 (= X3 (+ (* X2 S2) S3))
 (= X3 (- (* X2 S2) S3))
 (= X3 (- S2 (* X2 S3)))
 (= X3 (+ (* X2 S2) (* X2 S3)))
 (= X3 (- (* X2 S2) (* X2 S3)))
))
(assert (and (> X3 0) (< X3 4096) (power2 S2) (power2 S3)))
(assert (or
 (= X4 (+ (* 65 S4) S5))
 (= X4 (- (* 65 S4) S5))
 (= X4 (- S4 (* 65 S5)))
 (= X4 (+ (* 65 S4) (* 65 S5)))
 (= X4 (- (* 65 S4) (* 65 S5)))
 (= X4 (+ (* 65 S4) (* 975 S5)))
 (= X4 (- (* 65 S4) (* 975 S5)))
 (= X4 (- (* 975 S4) (* 65 S5)))
 (= X4 (+ (* 65 S4) (* X2 S5)))
 (= X4 (- (* 65 S4) (* X2 S5)))
 (= X4 (- (* X2 S4) (* 65 S5)))
 (= X4 (+ (* 65 S4) (* X3 S5)))
 (= X4 (- (* 65 S4) (* X3 S5)))
 (= X4 (- (* X3 S4) (* 65 S5)))
 (= X4 (+ (* 975 S4) S5))
 (= X4 (- (* 975 S4) S5))
 (= X4 (- S4 (* 975 S5)))
 (= X4 (+ (* 975 S4) (* 975 S5)))
 (= X4 (- (* 975 S4) (* 975 S5)))
 (= X4 (+ (* 975 S4) (* X2 S5)))
 (= X4 (- (* 975 S4) (* X2 S5)))
 (= X4 (- (* X2 S4) (* 975 S5)))
 (= X4 (+ (* 975 S4) (* X3 S5)))
 (= X4 (- (* 975 S4) (* X3 S5)))
 (= X4 (- (* X3 S4) (* 975 S5)))
 (= X4 (+ (* X2 S4) S5))
 (= X4 (- (* X2 S4) S5))
 (= X4 (- S4 (* X2 S5)))
 (= X4 (+ (* X2 S4) (* X2 S5)))
 (= X4 (- (* X2 S4) (* X2 S5)))
 (= X4 (+ (* X2 S4) (* X3 S5)))
 (= X4 (- (* X2 S4) (* X3 S5)))
 (= X4 (- (* X3 S4) (* X2 S5)))
 (= X4 (+ (* X3 S4) S5))
 (= X4 (- (* X3 S4) S5))
 (= X4 (- S4 (* X3 S5)))
 (= X4 (+ (* X3 S4) (* X3 S5)))
 (= X4 (- (* X3 S4) (* X3 S5)))
))
(assert (and (> X4 0) (< X4 4096) (power2 S4) (power2 S5)))
(assert (or
 (= X5 (+ (* 65 S6) S7))
 (= X5 (- (* 65 S6) S7))
 (= X5 (- S6 (* 65 S7)))
 (= X5 (+ (* 65 S6) (* 65 S7)))
 (= X5 (- (* 65 S6) (* 65 S7)))
 (= X5 (+ (* 65 S6) (* 975 S7)))
 (= X5 (- (* 65 S6) (* 975 S7)))
 (= X5 (- (* 975 S6) (* 65 S7)))
 (= X5 (+ (* 65 S6) (* X2 S7)))
 (= X5 (- (* 65 S6) (* X2 S7)))
 (= X5 (- (* X2 S6) (* 65 S7)))
 (= X5 (+ (* 65 S6) (* X3 S7)))
 (= X5 (- (* 65 S6) (* X3 S7)))
 (= X5 (- (* X3 S6) (* 65 S7)))
 (= X5 (+ (* 65 S6) (* X4 S7)))
 (= X5 (- (* 65 S6) (* X4 S7)))
 (= X5 (- (* X4 S6) (* 65 S7)))
 (= X5 (+ (* 975 S6) S7))
 (= X5 (- (* 975 S6) S7))
 (= X5 (- S6 (* 975 S7)))
 (= X5 (+ (* 975 S6) (* 975 S7)))
 (= X5 (- (* 975 S6) (* 975 S7)))
 (= X5 (+ (* 975 S6) (* X2 S7)))
 (= X5 (- (* 975 S6) (* X2 S7)))
 (= X5 (- (* X2 S6) (* 975 S7)))
 (= X5 (+ (* 975 S6) (* X3 S7)))
 (= X5 (- (* 975 S6) (* X3 S7)))
 (= X5 (- (* X3 S6) (* 975 S7)))
 (= X5 (+ (* 975 S6) (* X4 S7)))
 (= X5 (- (* 975 S6) (* X4 S7)))
 (= X5 (- (* X4 S6) (* 975 S7)))
 (= X5 (+ (* X2 S6) S7))
 (= X5 (- (* X2 S6) S7))
 (= X5 (- S6 (* X2 S7)))
 (= X5 (+ (* X2 S6) (* X2 S7)))
 (= X5 (- (* X2 S6) (* X2 S7)))
 (= X5 (+ (* X2 S6) (* X3 S7)))
 (= X5 (- (* X2 S6) (* X3 S7)))
 (= X5 (- (* X3 S6) (* X2 S7)))
 (= X5 (+ (* X2 S6) (* X4 S7)))
 (= X5 (- (* X2 S6) (* X4 S7)))
 (= X5 (- (* X4 S6) (* X2 S7)))
 (= X5 (+ (* X3 S6) S7))
 (= X5 (- (* X3 S6) S7))
 (= X5 (- S6 (* X3 S7)))
 (= X5 (+ (* X3 S6) (* X3 S7)))
 (= X5 (- (* X3 S6) (* X3 S7)))
 (= X5 (+ (* X3 S6) (* X4 S7)))
 (= X5 (- (* X3 S6) (* X4 S7)))
 (= X5 (- (* X4 S6) (* X3 S7)))
 (= X5 (+ (* X4 S6) S7))
 (= X5 (- (* X4 S6) S7))
 (= X5 (- S6 (* X4 S7)))
 (= X5 (+ (* X4 S6) (* X4 S7)))
 (= X5 (- (* X4 S6) (* X4 S7)))
))
(assert (and (> X5 0) (< X5 4096) (power2 S6) (power2 S7)))
(assert (or
 (= X6 (+ (* 65 S8) S9))
 (= X6 (- (* 65 S8) S9))
 (= X6 (- S8 (* 65 S9)))
 (= X6 (+ (* 65 S8) (* 65 S9)))
 (= X6 (- (* 65 S8) (* 65 S9)))
 (= X6 (+ (* 65 S8) (* 975 S9)))
 (= X6 (- (* 65 S8) (* 975 S9)))
 (= X6 (- (* 975 S8) (* 65 S9)))
 (= X6 (+ (* 65 S8) (* X2 S9)))
 (= X6 (- (* 65 S8) (* X2 S9)))
 (= X6 (- (* X2 S8) (* 65 S9)))
 (= X6 (+ (* 65 S8) (* X3 S9)))
 (= X6 (- (* 65 S8) (* X3 S9)))
 (= X6 (- (* X3 S8) (* 65 S9)))
 (= X6 (+ (* 65 S8) (* X4 S9)))
 (= X6 (- (* 65 S8) (* X4 S9)))
 (= X6 (- (* X4 S8) (* 65 S9)))
 (= X6 (+ (* 65 S8) (* X5 S9)))
 (= X6 (- (* 65 S8) (* X5 S9)))
 (= X6 (- (* X5 S8) (* 65 S9)))
 (= X6 (+ (* 975 S8) S9))
 (= X6 (- (* 975 S8) S9))
 (= X6 (- S8 (* 975 S9)))
 (= X6 (+ (* 975 S8) (* 975 S9)))
 (= X6 (- (* 975 S8) (* 975 S9)))
 (= X6 (+ (* 975 S8) (* X2 S9)))
 (= X6 (- (* 975 S8) (* X2 S9)))
 (= X6 (- (* X2 S8) (* 975 S9)))
 (= X6 (+ (* 975 S8) (* X3 S9)))
 (= X6 (- (* 975 S8) (* X3 S9)))
 (= X6 (- (* X3 S8) (* 975 S9)))
 (= X6 (+ (* 975 S8) (* X4 S9)))
 (= X6 (- (* 975 S8) (* X4 S9)))
 (= X6 (- (* X4 S8) (* 975 S9)))
 (= X6 (+ (* 975 S8) (* X5 S9)))
 (= X6 (- (* 975 S8) (* X5 S9)))
 (= X6 (- (* X5 S8) (* 975 S9)))
 (= X6 (+ (* X2 S8) S9))
 (= X6 (- (* X2 S8) S9))
 (= X6 (- S8 (* X2 S9)))
 (= X6 (+ (* X2 S8) (* X2 S9)))
 (= X6 (- (* X2 S8) (* X2 S9)))
 (= X6 (+ (* X2 S8) (* X3 S9)))
 (= X6 (- (* X2 S8) (* X3 S9)))
 (= X6 (- (* X3 S8) (* X2 S9)))
 (= X6 (+ (* X2 S8) (* X4 S9)))
 (= X6 (- (* X2 S8) (* X4 S9)))
 (= X6 (- (* X4 S8) (* X2 S9)))
 (= X6 (+ (* X2 S8) (* X5 S9)))
 (= X6 (- (* X2 S8) (* X5 S9)))
 (= X6 (- (* X5 S8) (* X2 S9)))
 (= X6 (+ (* X3 S8) S9))
 (= X6 (- (* X3 S8) S9))
 (= X6 (- S8 (* X3 S9)))
 (= X6 (+ (* X3 S8) (* X3 S9)))
 (= X6 (- (* X3 S8) (* X3 S9)))
 (= X6 (+ (* X3 S8) (* X4 S9)))
 (= X6 (- (* X3 S8) (* X4 S9)))
 (= X6 (- (* X4 S8) (* X3 S9)))
 (= X6 (+ (* X3 S8) (* X5 S9)))
 (= X6 (- (* X3 S8) (* X5 S9)))
 (= X6 (- (* X5 S8) (* X3 S9)))
 (= X6 (+ (* X4 S8) S9))
 (= X6 (- (* X4 S8) S9))
 (= X6 (- S8 (* X4 S9)))
 (= X6 (+ (* X4 S8) (* X4 S9)))
 (= X6 (- (* X4 S8) (* X4 S9)))
 (= X6 (+ (* X4 S8) (* X5 S9)))
 (= X6 (- (* X4 S8) (* X5 S9)))
 (= X6 (- (* X5 S8) (* X4 S9)))
 (= X6 (+ (* X5 S8) S9))
 (= X6 (- (* X5 S8) S9))
 (= X6 (- S8 (* X5 S9)))
 (= X6 (+ (* X5 S8) (* X5 S9)))
 (= X6 (- (* X5 S8) (* X5 S9)))
))
(assert (and (> X6 0) (< X6 4096) (power2 S8) (power2 S9)))
(assert (or
 (= X7 (+ (* 65 S10) S11))
 (= X7 (- (* 65 S10) S11))
 (= X7 (- S10 (* 65 S11)))
 (= X7 (+ (* 65 S10) (* 65 S11)))
 (= X7 (- (* 65 S10) (* 65 S11)))
 (= X7 (+ (* 65 S10) (* 975 S11)))
 (= X7 (- (* 65 S10) (* 975 S11)))
 (= X7 (- (* 975 S10) (* 65 S11)))
 (= X7 (+ (* 65 S10) (* X2 S11)))
 (= X7 (- (* 65 S10) (* X2 S11)))
 (= X7 (- (* X2 S10) (* 65 S11)))
 (= X7 (+ (* 65 S10) (* X3 S11)))
 (= X7 (- (* 65 S10) (* X3 S11)))
 (= X7 (- (* X3 S10) (* 65 S11)))
 (= X7 (+ (* 65 S10) (* X4 S11)))
 (= X7 (- (* 65 S10) (* X4 S11)))
 (= X7 (- (* X4 S10) (* 65 S11)))
 (= X7 (+ (* 65 S10) (* X5 S11)))
 (= X7 (- (* 65 S10) (* X5 S11)))
 (= X7 (- (* X5 S10) (* 65 S11)))
 (= X7 (+ (* 65 S10) (* X6 S11)))
 (= X7 (- (* 65 S10) (* X6 S11)))
 (= X7 (- (* X6 S10) (* 65 S11)))
 (= X7 (+ (* 975 S10) S11))
 (= X7 (- (* 975 S10) S11))
 (= X7 (- S10 (* 975 S11)))
 (= X7 (+ (* 975 S10) (* 975 S11)))
 (= X7 (- (* 975 S10) (* 975 S11)))
 (= X7 (+ (* 975 S10) (* X2 S11)))
 (= X7 (- (* 975 S10) (* X2 S11)))
 (= X7 (- (* X2 S10) (* 975 S11)))
 (= X7 (+ (* 975 S10) (* X3 S11)))
 (= X7 (- (* 975 S10) (* X3 S11)))
 (= X7 (- (* X3 S10) (* 975 S11)))
 (= X7 (+ (* 975 S10) (* X4 S11)))
 (= X7 (- (* 975 S10) (* X4 S11)))
 (= X7 (- (* X4 S10) (* 975 S11)))
 (= X7 (+ (* 975 S10) (* X5 S11)))
 (= X7 (- (* 975 S10) (* X5 S11)))
 (= X7 (- (* X5 S10) (* 975 S11)))
 (= X7 (+ (* 975 S10) (* X6 S11)))
 (= X7 (- (* 975 S10) (* X6 S11)))
 (= X7 (- (* X6 S10) (* 975 S11)))
 (= X7 (+ (* X2 S10) S11))
 (= X7 (- (* X2 S10) S11))
 (= X7 (- S10 (* X2 S11)))
 (= X7 (+ (* X2 S10) (* X2 S11)))
 (= X7 (- (* X2 S10) (* X2 S11)))
 (= X7 (+ (* X2 S10) (* X3 S11)))
 (= X7 (- (* X2 S10) (* X3 S11)))
 (= X7 (- (* X3 S10) (* X2 S11)))
 (= X7 (+ (* X2 S10) (* X4 S11)))
 (= X7 (- (* X2 S10) (* X4 S11)))
 (= X7 (- (* X4 S10) (* X2 S11)))
 (= X7 (+ (* X2 S10) (* X5 S11)))
 (= X7 (- (* X2 S10) (* X5 S11)))
 (= X7 (- (* X5 S10) (* X2 S11)))
 (= X7 (+ (* X2 S10) (* X6 S11)))
 (= X7 (- (* X2 S10) (* X6 S11)))
 (= X7 (- (* X6 S10) (* X2 S11)))
 (= X7 (+ (* X3 S10) S11))
 (= X7 (- (* X3 S10) S11))
 (= X7 (- S10 (* X3 S11)))
 (= X7 (+ (* X3 S10) (* X3 S11)))
 (= X7 (- (* X3 S10) (* X3 S11)))
 (= X7 (+ (* X3 S10) (* X4 S11)))
 (= X7 (- (* X3 S10) (* X4 S11)))
 (= X7 (- (* X4 S10) (* X3 S11)))
 (= X7 (+ (* X3 S10) (* X5 S11)))
 (= X7 (- (* X3 S10) (* X5 S11)))
 (= X7 (- (* X5 S10) (* X3 S11)))
 (= X7 (+ (* X3 S10) (* X6 S11)))
 (= X7 (- (* X3 S10) (* X6 S11)))
 (= X7 (- (* X6 S10) (* X3 S11)))
 (= X7 (+ (* X4 S10) S11))
 (= X7 (- (* X4 S10) S11))
 (= X7 (- S10 (* X4 S11)))
 (= X7 (+ (* X4 S10) (* X4 S11)))
 (= X7 (- (* X4 S10) (* X4 S11)))
 (= X7 (+ (* X4 S10) (* X5 S11)))
 (= X7 (- (* X4 S10) (* X5 S11)))
 (= X7 (- (* X5 S10) (* X4 S11)))
 (= X7 (+ (* X4 S10) (* X6 S11)))
 (= X7 (- (* X4 S10) (* X6 S11)))
 (= X7 (- (* X6 S10) (* X4 S11)))
 (= X7 (+ (* X5 S10) S11))
 (= X7 (- (* X5 S10) S11))
 (= X7 (- S10 (* X5 S11)))
 (= X7 (+ (* X5 S10) (* X5 S11)))
 (= X7 (- (* X5 S10) (* X5 S11)))
 (= X7 (+ (* X5 S10) (* X6 S11)))
 (= X7 (- (* X5 S10) (* X6 S11)))
 (= X7 (- (* X6 S10) (* X5 S11)))
 (= X7 (+ (* X6 S10) S11))
 (= X7 (- (* X6 S10) S11))
 (= X7 (- S10 (* X6 S11)))
 (= X7 (+ (* X6 S10) (* X6 S11)))
 (= X7 (- (* X6 S10) (* X6 S11)))
))
(assert (and (> X7 0) (< X7 4096) (power2 S10) (power2 S11)))
(assert (or
 (= X8 (+ (* 65 S12) S13))
 (= X8 (- (* 65 S12) S13))
 (= X8 (- S12 (* 65 S13)))
 (= X8 (+ (* 65 S12) (* 65 S13)))
 (= X8 (- (* 65 S12) (* 65 S13)))
 (= X8 (+ (* 65 S12) (* 975 S13)))
 (= X8 (- (* 65 S12) (* 975 S13)))
 (= X8 (- (* 975 S12) (* 65 S13)))
 (= X8 (+ (* 65 S12) (* X2 S13)))
 (= X8 (- (* 65 S12) (* X2 S13)))
 (= X8 (- (* X2 S12) (* 65 S13)))
 (= X8 (+ (* 65 S12) (* X3 S13)))
 (= X8 (- (* 65 S12) (* X3 S13)))
 (= X8 (- (* X3 S12) (* 65 S13)))
 (= X8 (+ (* 65 S12) (* X4 S13)))
 (= X8 (- (* 65 S12) (* X4 S13)))
 (= X8 (- (* X4 S12) (* 65 S13)))
 (= X8 (+ (* 65 S12) (* X5 S13)))
 (= X8 (- (* 65 S12) (* X5 S13)))
 (= X8 (- (* X5 S12) (* 65 S13)))
 (= X8 (+ (* 65 S12) (* X6 S13)))
 (= X8 (- (* 65 S12) (* X6 S13)))
 (= X8 (- (* X6 S12) (* 65 S13)))
 (= X8 (+ (* 65 S12) (* X7 S13)))
 (= X8 (- (* 65 S12) (* X7 S13)))
 (= X8 (- (* X7 S12) (* 65 S13)))
 (= X8 (+ (* 975 S12) S13))
 (= X8 (- (* 975 S12) S13))
 (= X8 (- S12 (* 975 S13)))
 (= X8 (+ (* 975 S12) (* 975 S13)))
 (= X8 (- (* 975 S12) (* 975 S13)))
 (= X8 (+ (* 975 S12) (* X2 S13)))
 (= X8 (- (* 975 S12) (* X2 S13)))
 (= X8 (- (* X2 S12) (* 975 S13)))
 (= X8 (+ (* 975 S12) (* X3 S13)))
 (= X8 (- (* 975 S12) (* X3 S13)))
 (= X8 (- (* X3 S12) (* 975 S13)))
 (= X8 (+ (* 975 S12) (* X4 S13)))
 (= X8 (- (* 975 S12) (* X4 S13)))
 (= X8 (- (* X4 S12) (* 975 S13)))
 (= X8 (+ (* 975 S12) (* X5 S13)))
 (= X8 (- (* 975 S12) (* X5 S13)))
 (= X8 (- (* X5 S12) (* 975 S13)))
 (= X8 (+ (* 975 S12) (* X6 S13)))
 (= X8 (- (* 975 S12) (* X6 S13)))
 (= X8 (- (* X6 S12) (* 975 S13)))
 (= X8 (+ (* 975 S12) (* X7 S13)))
 (= X8 (- (* 975 S12) (* X7 S13)))
 (= X8 (- (* X7 S12) (* 975 S13)))
 (= X8 (+ (* X2 S12) S13))
 (= X8 (- (* X2 S12) S13))
 (= X8 (- S12 (* X2 S13)))
 (= X8 (+ (* X2 S12) (* X2 S13)))
 (= X8 (- (* X2 S12) (* X2 S13)))
 (= X8 (+ (* X2 S12) (* X3 S13)))
 (= X8 (- (* X2 S12) (* X3 S13)))
 (= X8 (- (* X3 S12) (* X2 S13)))
 (= X8 (+ (* X2 S12) (* X4 S13)))
 (= X8 (- (* X2 S12) (* X4 S13)))
 (= X8 (- (* X4 S12) (* X2 S13)))
 (= X8 (+ (* X2 S12) (* X5 S13)))
 (= X8 (- (* X2 S12) (* X5 S13)))
 (= X8 (- (* X5 S12) (* X2 S13)))
 (= X8 (+ (* X2 S12) (* X6 S13)))
 (= X8 (- (* X2 S12) (* X6 S13)))
 (= X8 (- (* X6 S12) (* X2 S13)))
 (= X8 (+ (* X2 S12) (* X7 S13)))
 (= X8 (- (* X2 S12) (* X7 S13)))
 (= X8 (- (* X7 S12) (* X2 S13)))
 (= X8 (+ (* X3 S12) S13))
 (= X8 (- (* X3 S12) S13))
 (= X8 (- S12 (* X3 S13)))
 (= X8 (+ (* X3 S12) (* X3 S13)))
 (= X8 (- (* X3 S12) (* X3 S13)))
 (= X8 (+ (* X3 S12) (* X4 S13)))
 (= X8 (- (* X3 S12) (* X4 S13)))
 (= X8 (- (* X4 S12) (* X3 S13)))
 (= X8 (+ (* X3 S12) (* X5 S13)))
 (= X8 (- (* X3 S12) (* X5 S13)))
 (= X8 (- (* X5 S12) (* X3 S13)))
 (= X8 (+ (* X3 S12) (* X6 S13)))
 (= X8 (- (* X3 S12) (* X6 S13)))
 (= X8 (- (* X6 S12) (* X3 S13)))
 (= X8 (+ (* X3 S12) (* X7 S13)))
 (= X8 (- (* X3 S12) (* X7 S13)))
 (= X8 (- (* X7 S12) (* X3 S13)))
 (= X8 (+ (* X4 S12) S13))
 (= X8 (- (* X4 S12) S13))
 (= X8 (- S12 (* X4 S13)))
 (= X8 (+ (* X4 S12) (* X4 S13)))
 (= X8 (- (* X4 S12) (* X4 S13)))
 (= X8 (+ (* X4 S12) (* X5 S13)))
 (= X8 (- (* X4 S12) (* X5 S13)))
 (= X8 (- (* X5 S12) (* X4 S13)))
 (= X8 (+ (* X4 S12) (* X6 S13)))
 (= X8 (- (* X4 S12) (* X6 S13)))
 (= X8 (- (* X6 S12) (* X4 S13)))
 (= X8 (+ (* X4 S12) (* X7 S13)))
 (= X8 (- (* X4 S12) (* X7 S13)))
 (= X8 (- (* X7 S12) (* X4 S13)))
 (= X8 (+ (* X5 S12) S13))
 (= X8 (- (* X5 S12) S13))
 (= X8 (- S12 (* X5 S13)))
 (= X8 (+ (* X5 S12) (* X5 S13)))
 (= X8 (- (* X5 S12) (* X5 S13)))
 (= X8 (+ (* X5 S12) (* X6 S13)))
 (= X8 (- (* X5 S12) (* X6 S13)))
 (= X8 (- (* X6 S12) (* X5 S13)))
 (= X8 (+ (* X5 S12) (* X7 S13)))
 (= X8 (- (* X5 S12) (* X7 S13)))
 (= X8 (- (* X7 S12) (* X5 S13)))
 (= X8 (+ (* X6 S12) S13))
 (= X8 (- (* X6 S12) S13))
 (= X8 (- S12 (* X6 S13)))
 (= X8 (+ (* X6 S12) (* X6 S13)))
 (= X8 (- (* X6 S12) (* X6 S13)))
 (= X8 (+ (* X6 S12) (* X7 S13)))
 (= X8 (- (* X6 S12) (* X7 S13)))
 (= X8 (- (* X7 S12) (* X6 S13)))
 (= X8 (+ (* X7 S12) S13))
 (= X8 (- (* X7 S12) S13))
 (= X8 (- S12 (* X7 S13)))
 (= X8 (+ (* X7 S12) (* X7 S13)))
 (= X8 (- (* X7 S12) (* X7 S13)))
))
(assert (and (> X8 0) (< X8 4096) (power2 S12) (power2 S13)))
(assert (or
 (= X9 (+ (* 65 S14) S15))
 (= X9 (- (* 65 S14) S15))
 (= X9 (- S14 (* 65 S15)))
 (= X9 (+ (* 65 S14) (* 65 S15)))
 (= X9 (- (* 65 S14) (* 65 S15)))
 (= X9 (+ (* 65 S14) (* 975 S15)))
 (= X9 (- (* 65 S14) (* 975 S15)))
 (= X9 (- (* 975 S14) (* 65 S15)))
 (= X9 (+ (* 65 S14) (* X2 S15)))
 (= X9 (- (* 65 S14) (* X2 S15)))
 (= X9 (- (* X2 S14) (* 65 S15)))
 (= X9 (+ (* 65 S14) (* X3 S15)))
 (= X9 (- (* 65 S14) (* X3 S15)))
 (= X9 (- (* X3 S14) (* 65 S15)))
 (= X9 (+ (* 65 S14) (* X4 S15)))
 (= X9 (- (* 65 S14) (* X4 S15)))
 (= X9 (- (* X4 S14) (* 65 S15)))
 (= X9 (+ (* 65 S14) (* X5 S15)))
 (= X9 (- (* 65 S14) (* X5 S15)))
 (= X9 (- (* X5 S14) (* 65 S15)))
 (= X9 (+ (* 65 S14) (* X6 S15)))
 (= X9 (- (* 65 S14) (* X6 S15)))
 (= X9 (- (* X6 S14) (* 65 S15)))
 (= X9 (+ (* 65 S14) (* X7 S15)))
 (= X9 (- (* 65 S14) (* X7 S15)))
 (= X9 (- (* X7 S14) (* 65 S15)))
 (= X9 (+ (* 65 S14) (* X8 S15)))
 (= X9 (- (* 65 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* 65 S15)))
 (= X9 (+ (* 975 S14) S15))
 (= X9 (- (* 975 S14) S15))
 (= X9 (- S14 (* 975 S15)))
 (= X9 (+ (* 975 S14) (* 975 S15)))
 (= X9 (- (* 975 S14) (* 975 S15)))
 (= X9 (+ (* 975 S14) (* X2 S15)))
 (= X9 (- (* 975 S14) (* X2 S15)))
 (= X9 (- (* X2 S14) (* 975 S15)))
 (= X9 (+ (* 975 S14) (* X3 S15)))
 (= X9 (- (* 975 S14) (* X3 S15)))
 (= X9 (- (* X3 S14) (* 975 S15)))
 (= X9 (+ (* 975 S14) (* X4 S15)))
 (= X9 (- (* 975 S14) (* X4 S15)))
 (= X9 (- (* X4 S14) (* 975 S15)))
 (= X9 (+ (* 975 S14) (* X5 S15)))
 (= X9 (- (* 975 S14) (* X5 S15)))
 (= X9 (- (* X5 S14) (* 975 S15)))
 (= X9 (+ (* 975 S14) (* X6 S15)))
 (= X9 (- (* 975 S14) (* X6 S15)))
 (= X9 (- (* X6 S14) (* 975 S15)))
 (= X9 (+ (* 975 S14) (* X7 S15)))
 (= X9 (- (* 975 S14) (* X7 S15)))
 (= X9 (- (* X7 S14) (* 975 S15)))
 (= X9 (+ (* 975 S14) (* X8 S15)))
 (= X9 (- (* 975 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* 975 S15)))
 (= X9 (+ (* X2 S14) S15))
 (= X9 (- (* X2 S14) S15))
 (= X9 (- S14 (* X2 S15)))
 (= X9 (+ (* X2 S14) (* X2 S15)))
 (= X9 (- (* X2 S14) (* X2 S15)))
 (= X9 (+ (* X2 S14) (* X3 S15)))
 (= X9 (- (* X2 S14) (* X3 S15)))
 (= X9 (- (* X3 S14) (* X2 S15)))
 (= X9 (+ (* X2 S14) (* X4 S15)))
 (= X9 (- (* X2 S14) (* X4 S15)))
 (= X9 (- (* X4 S14) (* X2 S15)))
 (= X9 (+ (* X2 S14) (* X5 S15)))
 (= X9 (- (* X2 S14) (* X5 S15)))
 (= X9 (- (* X5 S14) (* X2 S15)))
 (= X9 (+ (* X2 S14) (* X6 S15)))
 (= X9 (- (* X2 S14) (* X6 S15)))
 (= X9 (- (* X6 S14) (* X2 S15)))
 (= X9 (+ (* X2 S14) (* X7 S15)))
 (= X9 (- (* X2 S14) (* X7 S15)))
 (= X9 (- (* X7 S14) (* X2 S15)))
 (= X9 (+ (* X2 S14) (* X8 S15)))
 (= X9 (- (* X2 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* X2 S15)))
 (= X9 (+ (* X3 S14) S15))
 (= X9 (- (* X3 S14) S15))
 (= X9 (- S14 (* X3 S15)))
 (= X9 (+ (* X3 S14) (* X3 S15)))
 (= X9 (- (* X3 S14) (* X3 S15)))
 (= X9 (+ (* X3 S14) (* X4 S15)))
 (= X9 (- (* X3 S14) (* X4 S15)))
 (= X9 (- (* X4 S14) (* X3 S15)))
 (= X9 (+ (* X3 S14) (* X5 S15)))
 (= X9 (- (* X3 S14) (* X5 S15)))
 (= X9 (- (* X5 S14) (* X3 S15)))
 (= X9 (+ (* X3 S14) (* X6 S15)))
 (= X9 (- (* X3 S14) (* X6 S15)))
 (= X9 (- (* X6 S14) (* X3 S15)))
 (= X9 (+ (* X3 S14) (* X7 S15)))
 (= X9 (- (* X3 S14) (* X7 S15)))
 (= X9 (- (* X7 S14) (* X3 S15)))
 (= X9 (+ (* X3 S14) (* X8 S15)))
 (= X9 (- (* X3 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* X3 S15)))
 (= X9 (+ (* X4 S14) S15))
 (= X9 (- (* X4 S14) S15))
 (= X9 (- S14 (* X4 S15)))
 (= X9 (+ (* X4 S14) (* X4 S15)))
 (= X9 (- (* X4 S14) (* X4 S15)))
 (= X9 (+ (* X4 S14) (* X5 S15)))
 (= X9 (- (* X4 S14) (* X5 S15)))
 (= X9 (- (* X5 S14) (* X4 S15)))
 (= X9 (+ (* X4 S14) (* X6 S15)))
 (= X9 (- (* X4 S14) (* X6 S15)))
 (= X9 (- (* X6 S14) (* X4 S15)))
 (= X9 (+ (* X4 S14) (* X7 S15)))
 (= X9 (- (* X4 S14) (* X7 S15)))
 (= X9 (- (* X7 S14) (* X4 S15)))
 (= X9 (+ (* X4 S14) (* X8 S15)))
 (= X9 (- (* X4 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* X4 S15)))
 (= X9 (+ (* X5 S14) S15))
 (= X9 (- (* X5 S14) S15))
 (= X9 (- S14 (* X5 S15)))
 (= X9 (+ (* X5 S14) (* X5 S15)))
 (= X9 (- (* X5 S14) (* X5 S15)))
 (= X9 (+ (* X5 S14) (* X6 S15)))
 (= X9 (- (* X5 S14) (* X6 S15)))
 (= X9 (- (* X6 S14) (* X5 S15)))
 (= X9 (+ (* X5 S14) (* X7 S15)))
 (= X9 (- (* X5 S14) (* X7 S15)))
 (= X9 (- (* X7 S14) (* X5 S15)))
 (= X9 (+ (* X5 S14) (* X8 S15)))
 (= X9 (- (* X5 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* X5 S15)))
 (= X9 (+ (* X6 S14) S15))
 (= X9 (- (* X6 S14) S15))
 (= X9 (- S14 (* X6 S15)))
 (= X9 (+ (* X6 S14) (* X6 S15)))
 (= X9 (- (* X6 S14) (* X6 S15)))
 (= X9 (+ (* X6 S14) (* X7 S15)))
 (= X9 (- (* X6 S14) (* X7 S15)))
 (= X9 (- (* X7 S14) (* X6 S15)))
 (= X9 (+ (* X6 S14) (* X8 S15)))
 (= X9 (- (* X6 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* X6 S15)))
 (= X9 (+ (* X7 S14) S15))
 (= X9 (- (* X7 S14) S15))
 (= X9 (- S14 (* X7 S15)))
 (= X9 (+ (* X7 S14) (* X7 S15)))
 (= X9 (- (* X7 S14) (* X7 S15)))
 (= X9 (+ (* X7 S14) (* X8 S15)))
 (= X9 (- (* X7 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* X7 S15)))
 (= X9 (+ (* X8 S14) S15))
 (= X9 (- (* X8 S14) S15))
 (= X9 (- S14 (* X8 S15)))
 (= X9 (+ (* X8 S14) (* X8 S15)))
 (= X9 (- (* X8 S14) (* X8 S15)))
))
(assert (and (> X9 0) (< X9 4096) (power2 S14) (power2 S15)))
(assert (or
 (= X10 (+ (* 65 S16) S17))
 (= X10 (- (* 65 S16) S17))
 (= X10 (- S16 (* 65 S17)))
 (= X10 (+ (* 65 S16) (* 65 S17)))
 (= X10 (- (* 65 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* 975 S17)))
 (= X10 (- (* 65 S16) (* 975 S17)))
 (= X10 (- (* 975 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* X2 S17)))
 (= X10 (- (* 65 S16) (* X2 S17)))
 (= X10 (- (* X2 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* X3 S17)))
 (= X10 (- (* 65 S16) (* X3 S17)))
 (= X10 (- (* X3 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* X4 S17)))
 (= X10 (- (* 65 S16) (* X4 S17)))
 (= X10 (- (* X4 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* X5 S17)))
 (= X10 (- (* 65 S16) (* X5 S17)))
 (= X10 (- (* X5 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* X6 S17)))
 (= X10 (- (* 65 S16) (* X6 S17)))
 (= X10 (- (* X6 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* X7 S17)))
 (= X10 (- (* 65 S16) (* X7 S17)))
 (= X10 (- (* X7 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* X8 S17)))
 (= X10 (- (* 65 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* 65 S17)))
 (= X10 (+ (* 65 S16) (* X9 S17)))
 (= X10 (- (* 65 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* 65 S17)))
 (= X10 (+ (* 975 S16) S17))
 (= X10 (- (* 975 S16) S17))
 (= X10 (- S16 (* 975 S17)))
 (= X10 (+ (* 975 S16) (* 975 S17)))
 (= X10 (- (* 975 S16) (* 975 S17)))
 (= X10 (+ (* 975 S16) (* X2 S17)))
 (= X10 (- (* 975 S16) (* X2 S17)))
 (= X10 (- (* X2 S16) (* 975 S17)))
 (= X10 (+ (* 975 S16) (* X3 S17)))
 (= X10 (- (* 975 S16) (* X3 S17)))
 (= X10 (- (* X3 S16) (* 975 S17)))
 (= X10 (+ (* 975 S16) (* X4 S17)))
 (= X10 (- (* 975 S16) (* X4 S17)))
 (= X10 (- (* X4 S16) (* 975 S17)))
 (= X10 (+ (* 975 S16) (* X5 S17)))
 (= X10 (- (* 975 S16) (* X5 S17)))
 (= X10 (- (* X5 S16) (* 975 S17)))
 (= X10 (+ (* 975 S16) (* X6 S17)))
 (= X10 (- (* 975 S16) (* X6 S17)))
 (= X10 (- (* X6 S16) (* 975 S17)))
 (= X10 (+ (* 975 S16) (* X7 S17)))
 (= X10 (- (* 975 S16) (* X7 S17)))
 (= X10 (- (* X7 S16) (* 975 S17)))
 (= X10 (+ (* 975 S16) (* X8 S17)))
 (= X10 (- (* 975 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* 975 S17)))
 (= X10 (+ (* 975 S16) (* X9 S17)))
 (= X10 (- (* 975 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* 975 S17)))
 (= X10 (+ (* X2 S16) S17))
 (= X10 (- (* X2 S16) S17))
 (= X10 (- S16 (* X2 S17)))
 (= X10 (+ (* X2 S16) (* X2 S17)))
 (= X10 (- (* X2 S16) (* X2 S17)))
 (= X10 (+ (* X2 S16) (* X3 S17)))
 (= X10 (- (* X2 S16) (* X3 S17)))
 (= X10 (- (* X3 S16) (* X2 S17)))
 (= X10 (+ (* X2 S16) (* X4 S17)))
 (= X10 (- (* X2 S16) (* X4 S17)))
 (= X10 (- (* X4 S16) (* X2 S17)))
 (= X10 (+ (* X2 S16) (* X5 S17)))
 (= X10 (- (* X2 S16) (* X5 S17)))
 (= X10 (- (* X5 S16) (* X2 S17)))
 (= X10 (+ (* X2 S16) (* X6 S17)))
 (= X10 (- (* X2 S16) (* X6 S17)))
 (= X10 (- (* X6 S16) (* X2 S17)))
 (= X10 (+ (* X2 S16) (* X7 S17)))
 (= X10 (- (* X2 S16) (* X7 S17)))
 (= X10 (- (* X7 S16) (* X2 S17)))
 (= X10 (+ (* X2 S16) (* X8 S17)))
 (= X10 (- (* X2 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* X2 S17)))
 (= X10 (+ (* X2 S16) (* X9 S17)))
 (= X10 (- (* X2 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* X2 S17)))
 (= X10 (+ (* X3 S16) S17))
 (= X10 (- (* X3 S16) S17))
 (= X10 (- S16 (* X3 S17)))
 (= X10 (+ (* X3 S16) (* X3 S17)))
 (= X10 (- (* X3 S16) (* X3 S17)))
 (= X10 (+ (* X3 S16) (* X4 S17)))
 (= X10 (- (* X3 S16) (* X4 S17)))
 (= X10 (- (* X4 S16) (* X3 S17)))
 (= X10 (+ (* X3 S16) (* X5 S17)))
 (= X10 (- (* X3 S16) (* X5 S17)))
 (= X10 (- (* X5 S16) (* X3 S17)))
 (= X10 (+ (* X3 S16) (* X6 S17)))
 (= X10 (- (* X3 S16) (* X6 S17)))
 (= X10 (- (* X6 S16) (* X3 S17)))
 (= X10 (+ (* X3 S16) (* X7 S17)))
 (= X10 (- (* X3 S16) (* X7 S17)))
 (= X10 (- (* X7 S16) (* X3 S17)))
 (= X10 (+ (* X3 S16) (* X8 S17)))
 (= X10 (- (* X3 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* X3 S17)))
 (= X10 (+ (* X3 S16) (* X9 S17)))
 (= X10 (- (* X3 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* X3 S17)))
 (= X10 (+ (* X4 S16) S17))
 (= X10 (- (* X4 S16) S17))
 (= X10 (- S16 (* X4 S17)))
 (= X10 (+ (* X4 S16) (* X4 S17)))
 (= X10 (- (* X4 S16) (* X4 S17)))
 (= X10 (+ (* X4 S16) (* X5 S17)))
 (= X10 (- (* X4 S16) (* X5 S17)))
 (= X10 (- (* X5 S16) (* X4 S17)))
 (= X10 (+ (* X4 S16) (* X6 S17)))
 (= X10 (- (* X4 S16) (* X6 S17)))
 (= X10 (- (* X6 S16) (* X4 S17)))
 (= X10 (+ (* X4 S16) (* X7 S17)))
 (= X10 (- (* X4 S16) (* X7 S17)))
 (= X10 (- (* X7 S16) (* X4 S17)))
 (= X10 (+ (* X4 S16) (* X8 S17)))
 (= X10 (- (* X4 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* X4 S17)))
 (= X10 (+ (* X4 S16) (* X9 S17)))
 (= X10 (- (* X4 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* X4 S17)))
 (= X10 (+ (* X5 S16) S17))
 (= X10 (- (* X5 S16) S17))
 (= X10 (- S16 (* X5 S17)))
 (= X10 (+ (* X5 S16) (* X5 S17)))
 (= X10 (- (* X5 S16) (* X5 S17)))
 (= X10 (+ (* X5 S16) (* X6 S17)))
 (= X10 (- (* X5 S16) (* X6 S17)))
 (= X10 (- (* X6 S16) (* X5 S17)))
 (= X10 (+ (* X5 S16) (* X7 S17)))
 (= X10 (- (* X5 S16) (* X7 S17)))
 (= X10 (- (* X7 S16) (* X5 S17)))
 (= X10 (+ (* X5 S16) (* X8 S17)))
 (= X10 (- (* X5 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* X5 S17)))
 (= X10 (+ (* X5 S16) (* X9 S17)))
 (= X10 (- (* X5 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* X5 S17)))
 (= X10 (+ (* X6 S16) S17))
 (= X10 (- (* X6 S16) S17))
 (= X10 (- S16 (* X6 S17)))
 (= X10 (+ (* X6 S16) (* X6 S17)))
 (= X10 (- (* X6 S16) (* X6 S17)))
 (= X10 (+ (* X6 S16) (* X7 S17)))
 (= X10 (- (* X6 S16) (* X7 S17)))
 (= X10 (- (* X7 S16) (* X6 S17)))
 (= X10 (+ (* X6 S16) (* X8 S17)))
 (= X10 (- (* X6 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* X6 S17)))
 (= X10 (+ (* X6 S16) (* X9 S17)))
 (= X10 (- (* X6 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* X6 S17)))
 (= X10 (+ (* X7 S16) S17))
 (= X10 (- (* X7 S16) S17))
 (= X10 (- S16 (* X7 S17)))
 (= X10 (+ (* X7 S16) (* X7 S17)))
 (= X10 (- (* X7 S16) (* X7 S17)))
 (= X10 (+ (* X7 S16) (* X8 S17)))
 (= X10 (- (* X7 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* X7 S17)))
 (= X10 (+ (* X7 S16) (* X9 S17)))
 (= X10 (- (* X7 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* X7 S17)))
 (= X10 (+ (* X8 S16) S17))
 (= X10 (- (* X8 S16) S17))
 (= X10 (- S16 (* X8 S17)))
 (= X10 (+ (* X8 S16) (* X8 S17)))
 (= X10 (- (* X8 S16) (* X8 S17)))
 (= X10 (+ (* X8 S16) (* X9 S17)))
 (= X10 (- (* X8 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* X8 S17)))
 (= X10 (+ (* X9 S16) S17))
 (= X10 (- (* X9 S16) S17))
 (= X10 (- S16 (* X9 S17)))
 (= X10 (+ (* X9 S16) (* X9 S17)))
 (= X10 (- (* X9 S16) (* X9 S17)))
))
(assert (and (> X10 0) (< X10 4096) (power2 S16) (power2 S17)))
(assert (or
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
 (= X3 143)
 (= X4 143)
 (= X5 143)
 (= X6 143)
 (= X7 143)
 (= X8 143)
 (= X9 143)
 (= X10 143)
))
(assert (or
 (= X3 167)
 (= X4 167)
 (= X5 167)
 (= X6 167)
 (= X7 167)
 (= X8 167)
 (= X9 167)
 (= X10 167)
))
(assert (or
 (= X3 121)
 (= X4 121)
 (= X5 121)
 (= X6 121)
 (= X7 121)
 (= X8 121)
 (= X9 121)
 (= X10 121)
))
(assert (or
 (= X3 1935)
 (= X4 1935)
 (= X5 1935)
 (= X6 1935)
 (= X7 1935)
 (= X8 1935)
 (= X9 1935)
 (= X10 1935)
))
(assert (or
 (= X3 1683)
 (= X4 1683)
 (= X5 1683)
 (= X6 1683)
 (= X7 1683)
 (= X8 1683)
 (= X9 1683)
 (= X10 1683)
))
(assert (or
 (= X3 1249)
 (= X4 1249)
 (= X5 1249)
 (= X6 1249)
 (= X7 1249)
 (= X8 1249)
 (= X9 1249)
 (= X10 1249)
))
(assert (or
 (= X3 41)
 (= X4 41)
 (= X5 41)
 (= X6 41)
 (= X7 41)
 (= X8 41)
 (= X9 41)
 (= X10 41)
))
(check-sat)
(exit)
