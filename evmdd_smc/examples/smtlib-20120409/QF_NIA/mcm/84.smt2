(set-logic QF_NIA)
(set-info :source |
 more info in 'N. P. Lopes, L. Aksoy, V. Manquinho, J. Monteiro.
 Optimally Solving the MCM Problem Using Pseudo-Boolean Satisfiability.
 Technical Report RT/43/2010, INESC-ID, Nov. 2010'. |)
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
(define-fun power2 ((x Int)) Bool
  (or (= x 1024) (= x 512) (= x 256) (= x 128) (= x 64) (= x 32) (= x 16) (= x 8) (= x 4) (= x 2) (= x 1)))
(assert (or
 (= X5 (+ S0 S1))
 (= X5 (- S0 S1))
 (= X5 (+ (* 33 S0) S1))
 (= X5 (- (* 33 S0) S1))
 (= X5 (- S0 (* 33 S1)))
 (= X5 (+ (* 33 S0) (* 33 S1)))
 (= X5 (- (* 33 S0) (* 33 S1)))
 (= X5 (+ (* 33 S0) (* 263 S1)))
 (= X5 (- (* 33 S0) (* 263 S1)))
 (= X5 (- (* 263 S0) (* 33 S1)))
 (= X5 (+ (* 33 S0) (* 97 S1)))
 (= X5 (- (* 33 S0) (* 97 S1)))
 (= X5 (- (* 97 S0) (* 33 S1)))
 (= X5 (+ (* 33 S0) (* 493 S1)))
 (= X5 (- (* 33 S0) (* 493 S1)))
 (= X5 (- (* 493 S0) (* 33 S1)))
 (= X5 (+ (* 33 S0) (* 19 S1)))
 (= X5 (- (* 33 S0) (* 19 S1)))
 (= X5 (- (* 19 S0) (* 33 S1)))
 (= X5 (+ (* 263 S0) S1))
 (= X5 (- (* 263 S0) S1))
 (= X5 (- S0 (* 263 S1)))
 (= X5 (+ (* 263 S0) (* 263 S1)))
 (= X5 (- (* 263 S0) (* 263 S1)))
 (= X5 (+ (* 263 S0) (* 97 S1)))
 (= X5 (- (* 263 S0) (* 97 S1)))
 (= X5 (- (* 97 S0) (* 263 S1)))
 (= X5 (+ (* 263 S0) (* 493 S1)))
 (= X5 (- (* 263 S0) (* 493 S1)))
 (= X5 (- (* 493 S0) (* 263 S1)))
 (= X5 (+ (* 263 S0) (* 19 S1)))
 (= X5 (- (* 263 S0) (* 19 S1)))
 (= X5 (- (* 19 S0) (* 263 S1)))
 (= X5 (+ (* 97 S0) S1))
 (= X5 (- (* 97 S0) S1))
 (= X5 (- S0 (* 97 S1)))
 (= X5 (+ (* 97 S0) (* 97 S1)))
 (= X5 (- (* 97 S0) (* 97 S1)))
 (= X5 (+ (* 97 S0) (* 493 S1)))
 (= X5 (- (* 97 S0) (* 493 S1)))
 (= X5 (- (* 493 S0) (* 97 S1)))
 (= X5 (+ (* 97 S0) (* 19 S1)))
 (= X5 (- (* 97 S0) (* 19 S1)))
 (= X5 (- (* 19 S0) (* 97 S1)))
 (= X5 (+ (* 493 S0) S1))
 (= X5 (- (* 493 S0) S1))
 (= X5 (- S0 (* 493 S1)))
 (= X5 (+ (* 493 S0) (* 493 S1)))
 (= X5 (- (* 493 S0) (* 493 S1)))
 (= X5 (+ (* 493 S0) (* 19 S1)))
 (= X5 (- (* 493 S0) (* 19 S1)))
 (= X5 (- (* 19 S0) (* 493 S1)))
 (= X5 (+ (* 19 S0) S1))
 (= X5 (- (* 19 S0) S1))
 (= X5 (- S0 (* 19 S1)))
 (= X5 (+ (* 19 S0) (* 19 S1)))
 (= X5 (- (* 19 S0) (* 19 S1)))
))
(assert (and (> X5 0) (< X5 2048) (power2 S0) (power2 S1)))
(assert (or
 (= X6 (+ (* 33 S2) S3))
 (= X6 (- (* 33 S2) S3))
 (= X6 (- S2 (* 33 S3)))
 (= X6 (+ (* 33 S2) (* 33 S3)))
 (= X6 (- (* 33 S2) (* 33 S3)))
 (= X6 (+ (* 33 S2) (* 263 S3)))
 (= X6 (- (* 33 S2) (* 263 S3)))
 (= X6 (- (* 263 S2) (* 33 S3)))
 (= X6 (+ (* 33 S2) (* 97 S3)))
 (= X6 (- (* 33 S2) (* 97 S3)))
 (= X6 (- (* 97 S2) (* 33 S3)))
 (= X6 (+ (* 33 S2) (* 493 S3)))
 (= X6 (- (* 33 S2) (* 493 S3)))
 (= X6 (- (* 493 S2) (* 33 S3)))
 (= X6 (+ (* 33 S2) (* 19 S3)))
 (= X6 (- (* 33 S2) (* 19 S3)))
 (= X6 (- (* 19 S2) (* 33 S3)))
 (= X6 (+ (* 33 S2) (* X5 S3)))
 (= X6 (- (* 33 S2) (* X5 S3)))
 (= X6 (- (* X5 S2) (* 33 S3)))
 (= X6 (+ (* 263 S2) S3))
 (= X6 (- (* 263 S2) S3))
 (= X6 (- S2 (* 263 S3)))
 (= X6 (+ (* 263 S2) (* 263 S3)))
 (= X6 (- (* 263 S2) (* 263 S3)))
 (= X6 (+ (* 263 S2) (* 97 S3)))
 (= X6 (- (* 263 S2) (* 97 S3)))
 (= X6 (- (* 97 S2) (* 263 S3)))
 (= X6 (+ (* 263 S2) (* 493 S3)))
 (= X6 (- (* 263 S2) (* 493 S3)))
 (= X6 (- (* 493 S2) (* 263 S3)))
 (= X6 (+ (* 263 S2) (* 19 S3)))
 (= X6 (- (* 263 S2) (* 19 S3)))
 (= X6 (- (* 19 S2) (* 263 S3)))
 (= X6 (+ (* 263 S2) (* X5 S3)))
 (= X6 (- (* 263 S2) (* X5 S3)))
 (= X6 (- (* X5 S2) (* 263 S3)))
 (= X6 (+ (* 97 S2) S3))
 (= X6 (- (* 97 S2) S3))
 (= X6 (- S2 (* 97 S3)))
 (= X6 (+ (* 97 S2) (* 97 S3)))
 (= X6 (- (* 97 S2) (* 97 S3)))
 (= X6 (+ (* 97 S2) (* 493 S3)))
 (= X6 (- (* 97 S2) (* 493 S3)))
 (= X6 (- (* 493 S2) (* 97 S3)))
 (= X6 (+ (* 97 S2) (* 19 S3)))
 (= X6 (- (* 97 S2) (* 19 S3)))
 (= X6 (- (* 19 S2) (* 97 S3)))
 (= X6 (+ (* 97 S2) (* X5 S3)))
 (= X6 (- (* 97 S2) (* X5 S3)))
 (= X6 (- (* X5 S2) (* 97 S3)))
 (= X6 (+ (* 493 S2) S3))
 (= X6 (- (* 493 S2) S3))
 (= X6 (- S2 (* 493 S3)))
 (= X6 (+ (* 493 S2) (* 493 S3)))
 (= X6 (- (* 493 S2) (* 493 S3)))
 (= X6 (+ (* 493 S2) (* 19 S3)))
 (= X6 (- (* 493 S2) (* 19 S3)))
 (= X6 (- (* 19 S2) (* 493 S3)))
 (= X6 (+ (* 493 S2) (* X5 S3)))
 (= X6 (- (* 493 S2) (* X5 S3)))
 (= X6 (- (* X5 S2) (* 493 S3)))
 (= X6 (+ (* 19 S2) S3))
 (= X6 (- (* 19 S2) S3))
 (= X6 (- S2 (* 19 S3)))
 (= X6 (+ (* 19 S2) (* 19 S3)))
 (= X6 (- (* 19 S2) (* 19 S3)))
 (= X6 (+ (* 19 S2) (* X5 S3)))
 (= X6 (- (* 19 S2) (* X5 S3)))
 (= X6 (- (* X5 S2) (* 19 S3)))
 (= X6 (+ (* X5 S2) S3))
 (= X6 (- (* X5 S2) S3))
 (= X6 (- S2 (* X5 S3)))
 (= X6 (+ (* X5 S2) (* X5 S3)))
 (= X6 (- (* X5 S2) (* X5 S3)))
))
(assert (and (> X6 0) (< X6 2048) (power2 S2) (power2 S3)))
(assert (or
 (= X7 (+ (* 33 S4) S5))
 (= X7 (- (* 33 S4) S5))
 (= X7 (- S4 (* 33 S5)))
 (= X7 (+ (* 33 S4) (* 33 S5)))
 (= X7 (- (* 33 S4) (* 33 S5)))
 (= X7 (+ (* 33 S4) (* 263 S5)))
 (= X7 (- (* 33 S4) (* 263 S5)))
 (= X7 (- (* 263 S4) (* 33 S5)))
 (= X7 (+ (* 33 S4) (* 97 S5)))
 (= X7 (- (* 33 S4) (* 97 S5)))
 (= X7 (- (* 97 S4) (* 33 S5)))
 (= X7 (+ (* 33 S4) (* 493 S5)))
 (= X7 (- (* 33 S4) (* 493 S5)))
 (= X7 (- (* 493 S4) (* 33 S5)))
 (= X7 (+ (* 33 S4) (* 19 S5)))
 (= X7 (- (* 33 S4) (* 19 S5)))
 (= X7 (- (* 19 S4) (* 33 S5)))
 (= X7 (+ (* 33 S4) (* X5 S5)))
 (= X7 (- (* 33 S4) (* X5 S5)))
 (= X7 (- (* X5 S4) (* 33 S5)))
 (= X7 (+ (* 33 S4) (* X6 S5)))
 (= X7 (- (* 33 S4) (* X6 S5)))
 (= X7 (- (* X6 S4) (* 33 S5)))
 (= X7 (+ (* 263 S4) S5))
 (= X7 (- (* 263 S4) S5))
 (= X7 (- S4 (* 263 S5)))
 (= X7 (+ (* 263 S4) (* 263 S5)))
 (= X7 (- (* 263 S4) (* 263 S5)))
 (= X7 (+ (* 263 S4) (* 97 S5)))
 (= X7 (- (* 263 S4) (* 97 S5)))
 (= X7 (- (* 97 S4) (* 263 S5)))
 (= X7 (+ (* 263 S4) (* 493 S5)))
 (= X7 (- (* 263 S4) (* 493 S5)))
 (= X7 (- (* 493 S4) (* 263 S5)))
 (= X7 (+ (* 263 S4) (* 19 S5)))
 (= X7 (- (* 263 S4) (* 19 S5)))
 (= X7 (- (* 19 S4) (* 263 S5)))
 (= X7 (+ (* 263 S4) (* X5 S5)))
 (= X7 (- (* 263 S4) (* X5 S5)))
 (= X7 (- (* X5 S4) (* 263 S5)))
 (= X7 (+ (* 263 S4) (* X6 S5)))
 (= X7 (- (* 263 S4) (* X6 S5)))
 (= X7 (- (* X6 S4) (* 263 S5)))
 (= X7 (+ (* 97 S4) S5))
 (= X7 (- (* 97 S4) S5))
 (= X7 (- S4 (* 97 S5)))
 (= X7 (+ (* 97 S4) (* 97 S5)))
 (= X7 (- (* 97 S4) (* 97 S5)))
 (= X7 (+ (* 97 S4) (* 493 S5)))
 (= X7 (- (* 97 S4) (* 493 S5)))
 (= X7 (- (* 493 S4) (* 97 S5)))
 (= X7 (+ (* 97 S4) (* 19 S5)))
 (= X7 (- (* 97 S4) (* 19 S5)))
 (= X7 (- (* 19 S4) (* 97 S5)))
 (= X7 (+ (* 97 S4) (* X5 S5)))
 (= X7 (- (* 97 S4) (* X5 S5)))
 (= X7 (- (* X5 S4) (* 97 S5)))
 (= X7 (+ (* 97 S4) (* X6 S5)))
 (= X7 (- (* 97 S4) (* X6 S5)))
 (= X7 (- (* X6 S4) (* 97 S5)))
 (= X7 (+ (* 493 S4) S5))
 (= X7 (- (* 493 S4) S5))
 (= X7 (- S4 (* 493 S5)))
 (= X7 (+ (* 493 S4) (* 493 S5)))
 (= X7 (- (* 493 S4) (* 493 S5)))
 (= X7 (+ (* 493 S4) (* 19 S5)))
 (= X7 (- (* 493 S4) (* 19 S5)))
 (= X7 (- (* 19 S4) (* 493 S5)))
 (= X7 (+ (* 493 S4) (* X5 S5)))
 (= X7 (- (* 493 S4) (* X5 S5)))
 (= X7 (- (* X5 S4) (* 493 S5)))
 (= X7 (+ (* 493 S4) (* X6 S5)))
 (= X7 (- (* 493 S4) (* X6 S5)))
 (= X7 (- (* X6 S4) (* 493 S5)))
 (= X7 (+ (* 19 S4) S5))
 (= X7 (- (* 19 S4) S5))
 (= X7 (- S4 (* 19 S5)))
 (= X7 (+ (* 19 S4) (* 19 S5)))
 (= X7 (- (* 19 S4) (* 19 S5)))
 (= X7 (+ (* 19 S4) (* X5 S5)))
 (= X7 (- (* 19 S4) (* X5 S5)))
 (= X7 (- (* X5 S4) (* 19 S5)))
 (= X7 (+ (* 19 S4) (* X6 S5)))
 (= X7 (- (* 19 S4) (* X6 S5)))
 (= X7 (- (* X6 S4) (* 19 S5)))
 (= X7 (+ (* X5 S4) S5))
 (= X7 (- (* X5 S4) S5))
 (= X7 (- S4 (* X5 S5)))
 (= X7 (+ (* X5 S4) (* X5 S5)))
 (= X7 (- (* X5 S4) (* X5 S5)))
 (= X7 (+ (* X5 S4) (* X6 S5)))
 (= X7 (- (* X5 S4) (* X6 S5)))
 (= X7 (- (* X6 S4) (* X5 S5)))
 (= X7 (+ (* X6 S4) S5))
 (= X7 (- (* X6 S4) S5))
 (= X7 (- S4 (* X6 S5)))
 (= X7 (+ (* X6 S4) (* X6 S5)))
 (= X7 (- (* X6 S4) (* X6 S5)))
))
(assert (and (> X7 0) (< X7 2048) (power2 S4) (power2 S5)))
(assert (or
 (= X8 (+ (* 33 S6) S7))
 (= X8 (- (* 33 S6) S7))
 (= X8 (- S6 (* 33 S7)))
 (= X8 (+ (* 33 S6) (* 33 S7)))
 (= X8 (- (* 33 S6) (* 33 S7)))
 (= X8 (+ (* 33 S6) (* 263 S7)))
 (= X8 (- (* 33 S6) (* 263 S7)))
 (= X8 (- (* 263 S6) (* 33 S7)))
 (= X8 (+ (* 33 S6) (* 97 S7)))
 (= X8 (- (* 33 S6) (* 97 S7)))
 (= X8 (- (* 97 S6) (* 33 S7)))
 (= X8 (+ (* 33 S6) (* 493 S7)))
 (= X8 (- (* 33 S6) (* 493 S7)))
 (= X8 (- (* 493 S6) (* 33 S7)))
 (= X8 (+ (* 33 S6) (* 19 S7)))
 (= X8 (- (* 33 S6) (* 19 S7)))
 (= X8 (- (* 19 S6) (* 33 S7)))
 (= X8 (+ (* 33 S6) (* X5 S7)))
 (= X8 (- (* 33 S6) (* X5 S7)))
 (= X8 (- (* X5 S6) (* 33 S7)))
 (= X8 (+ (* 33 S6) (* X6 S7)))
 (= X8 (- (* 33 S6) (* X6 S7)))
 (= X8 (- (* X6 S6) (* 33 S7)))
 (= X8 (+ (* 33 S6) (* X7 S7)))
 (= X8 (- (* 33 S6) (* X7 S7)))
 (= X8 (- (* X7 S6) (* 33 S7)))
 (= X8 (+ (* 263 S6) S7))
 (= X8 (- (* 263 S6) S7))
 (= X8 (- S6 (* 263 S7)))
 (= X8 (+ (* 263 S6) (* 263 S7)))
 (= X8 (- (* 263 S6) (* 263 S7)))
 (= X8 (+ (* 263 S6) (* 97 S7)))
 (= X8 (- (* 263 S6) (* 97 S7)))
 (= X8 (- (* 97 S6) (* 263 S7)))
 (= X8 (+ (* 263 S6) (* 493 S7)))
 (= X8 (- (* 263 S6) (* 493 S7)))
 (= X8 (- (* 493 S6) (* 263 S7)))
 (= X8 (+ (* 263 S6) (* 19 S7)))
 (= X8 (- (* 263 S6) (* 19 S7)))
 (= X8 (- (* 19 S6) (* 263 S7)))
 (= X8 (+ (* 263 S6) (* X5 S7)))
 (= X8 (- (* 263 S6) (* X5 S7)))
 (= X8 (- (* X5 S6) (* 263 S7)))
 (= X8 (+ (* 263 S6) (* X6 S7)))
 (= X8 (- (* 263 S6) (* X6 S7)))
 (= X8 (- (* X6 S6) (* 263 S7)))
 (= X8 (+ (* 263 S6) (* X7 S7)))
 (= X8 (- (* 263 S6) (* X7 S7)))
 (= X8 (- (* X7 S6) (* 263 S7)))
 (= X8 (+ (* 97 S6) S7))
 (= X8 (- (* 97 S6) S7))
 (= X8 (- S6 (* 97 S7)))
 (= X8 (+ (* 97 S6) (* 97 S7)))
 (= X8 (- (* 97 S6) (* 97 S7)))
 (= X8 (+ (* 97 S6) (* 493 S7)))
 (= X8 (- (* 97 S6) (* 493 S7)))
 (= X8 (- (* 493 S6) (* 97 S7)))
 (= X8 (+ (* 97 S6) (* 19 S7)))
 (= X8 (- (* 97 S6) (* 19 S7)))
 (= X8 (- (* 19 S6) (* 97 S7)))
 (= X8 (+ (* 97 S6) (* X5 S7)))
 (= X8 (- (* 97 S6) (* X5 S7)))
 (= X8 (- (* X5 S6) (* 97 S7)))
 (= X8 (+ (* 97 S6) (* X6 S7)))
 (= X8 (- (* 97 S6) (* X6 S7)))
 (= X8 (- (* X6 S6) (* 97 S7)))
 (= X8 (+ (* 97 S6) (* X7 S7)))
 (= X8 (- (* 97 S6) (* X7 S7)))
 (= X8 (- (* X7 S6) (* 97 S7)))
 (= X8 (+ (* 493 S6) S7))
 (= X8 (- (* 493 S6) S7))
 (= X8 (- S6 (* 493 S7)))
 (= X8 (+ (* 493 S6) (* 493 S7)))
 (= X8 (- (* 493 S6) (* 493 S7)))
 (= X8 (+ (* 493 S6) (* 19 S7)))
 (= X8 (- (* 493 S6) (* 19 S7)))
 (= X8 (- (* 19 S6) (* 493 S7)))
 (= X8 (+ (* 493 S6) (* X5 S7)))
 (= X8 (- (* 493 S6) (* X5 S7)))
 (= X8 (- (* X5 S6) (* 493 S7)))
 (= X8 (+ (* 493 S6) (* X6 S7)))
 (= X8 (- (* 493 S6) (* X6 S7)))
 (= X8 (- (* X6 S6) (* 493 S7)))
 (= X8 (+ (* 493 S6) (* X7 S7)))
 (= X8 (- (* 493 S6) (* X7 S7)))
 (= X8 (- (* X7 S6) (* 493 S7)))
 (= X8 (+ (* 19 S6) S7))
 (= X8 (- (* 19 S6) S7))
 (= X8 (- S6 (* 19 S7)))
 (= X8 (+ (* 19 S6) (* 19 S7)))
 (= X8 (- (* 19 S6) (* 19 S7)))
 (= X8 (+ (* 19 S6) (* X5 S7)))
 (= X8 (- (* 19 S6) (* X5 S7)))
 (= X8 (- (* X5 S6) (* 19 S7)))
 (= X8 (+ (* 19 S6) (* X6 S7)))
 (= X8 (- (* 19 S6) (* X6 S7)))
 (= X8 (- (* X6 S6) (* 19 S7)))
 (= X8 (+ (* 19 S6) (* X7 S7)))
 (= X8 (- (* 19 S6) (* X7 S7)))
 (= X8 (- (* X7 S6) (* 19 S7)))
 (= X8 (+ (* X5 S6) S7))
 (= X8 (- (* X5 S6) S7))
 (= X8 (- S6 (* X5 S7)))
 (= X8 (+ (* X5 S6) (* X5 S7)))
 (= X8 (- (* X5 S6) (* X5 S7)))
 (= X8 (+ (* X5 S6) (* X6 S7)))
 (= X8 (- (* X5 S6) (* X6 S7)))
 (= X8 (- (* X6 S6) (* X5 S7)))
 (= X8 (+ (* X5 S6) (* X7 S7)))
 (= X8 (- (* X5 S6) (* X7 S7)))
 (= X8 (- (* X7 S6) (* X5 S7)))
 (= X8 (+ (* X6 S6) S7))
 (= X8 (- (* X6 S6) S7))
 (= X8 (- S6 (* X6 S7)))
 (= X8 (+ (* X6 S6) (* X6 S7)))
 (= X8 (- (* X6 S6) (* X6 S7)))
 (= X8 (+ (* X6 S6) (* X7 S7)))
 (= X8 (- (* X6 S6) (* X7 S7)))
 (= X8 (- (* X7 S6) (* X6 S7)))
 (= X8 (+ (* X7 S6) S7))
 (= X8 (- (* X7 S6) S7))
 (= X8 (- S6 (* X7 S7)))
 (= X8 (+ (* X7 S6) (* X7 S7)))
 (= X8 (- (* X7 S6) (* X7 S7)))
))
(assert (and (> X8 0) (< X8 2048) (power2 S6) (power2 S7)))
(assert (or
 (= X9 (+ (* 33 S8) S9))
 (= X9 (- (* 33 S8) S9))
 (= X9 (- S8 (* 33 S9)))
 (= X9 (+ (* 33 S8) (* 33 S9)))
 (= X9 (- (* 33 S8) (* 33 S9)))
 (= X9 (+ (* 33 S8) (* 263 S9)))
 (= X9 (- (* 33 S8) (* 263 S9)))
 (= X9 (- (* 263 S8) (* 33 S9)))
 (= X9 (+ (* 33 S8) (* 97 S9)))
 (= X9 (- (* 33 S8) (* 97 S9)))
 (= X9 (- (* 97 S8) (* 33 S9)))
 (= X9 (+ (* 33 S8) (* 493 S9)))
 (= X9 (- (* 33 S8) (* 493 S9)))
 (= X9 (- (* 493 S8) (* 33 S9)))
 (= X9 (+ (* 33 S8) (* 19 S9)))
 (= X9 (- (* 33 S8) (* 19 S9)))
 (= X9 (- (* 19 S8) (* 33 S9)))
 (= X9 (+ (* 33 S8) (* X5 S9)))
 (= X9 (- (* 33 S8) (* X5 S9)))
 (= X9 (- (* X5 S8) (* 33 S9)))
 (= X9 (+ (* 33 S8) (* X6 S9)))
 (= X9 (- (* 33 S8) (* X6 S9)))
 (= X9 (- (* X6 S8) (* 33 S9)))
 (= X9 (+ (* 33 S8) (* X7 S9)))
 (= X9 (- (* 33 S8) (* X7 S9)))
 (= X9 (- (* X7 S8) (* 33 S9)))
 (= X9 (+ (* 33 S8) (* X8 S9)))
 (= X9 (- (* 33 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* 33 S9)))
 (= X9 (+ (* 263 S8) S9))
 (= X9 (- (* 263 S8) S9))
 (= X9 (- S8 (* 263 S9)))
 (= X9 (+ (* 263 S8) (* 263 S9)))
 (= X9 (- (* 263 S8) (* 263 S9)))
 (= X9 (+ (* 263 S8) (* 97 S9)))
 (= X9 (- (* 263 S8) (* 97 S9)))
 (= X9 (- (* 97 S8) (* 263 S9)))
 (= X9 (+ (* 263 S8) (* 493 S9)))
 (= X9 (- (* 263 S8) (* 493 S9)))
 (= X9 (- (* 493 S8) (* 263 S9)))
 (= X9 (+ (* 263 S8) (* 19 S9)))
 (= X9 (- (* 263 S8) (* 19 S9)))
 (= X9 (- (* 19 S8) (* 263 S9)))
 (= X9 (+ (* 263 S8) (* X5 S9)))
 (= X9 (- (* 263 S8) (* X5 S9)))
 (= X9 (- (* X5 S8) (* 263 S9)))
 (= X9 (+ (* 263 S8) (* X6 S9)))
 (= X9 (- (* 263 S8) (* X6 S9)))
 (= X9 (- (* X6 S8) (* 263 S9)))
 (= X9 (+ (* 263 S8) (* X7 S9)))
 (= X9 (- (* 263 S8) (* X7 S9)))
 (= X9 (- (* X7 S8) (* 263 S9)))
 (= X9 (+ (* 263 S8) (* X8 S9)))
 (= X9 (- (* 263 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* 263 S9)))
 (= X9 (+ (* 97 S8) S9))
 (= X9 (- (* 97 S8) S9))
 (= X9 (- S8 (* 97 S9)))
 (= X9 (+ (* 97 S8) (* 97 S9)))
 (= X9 (- (* 97 S8) (* 97 S9)))
 (= X9 (+ (* 97 S8) (* 493 S9)))
 (= X9 (- (* 97 S8) (* 493 S9)))
 (= X9 (- (* 493 S8) (* 97 S9)))
 (= X9 (+ (* 97 S8) (* 19 S9)))
 (= X9 (- (* 97 S8) (* 19 S9)))
 (= X9 (- (* 19 S8) (* 97 S9)))
 (= X9 (+ (* 97 S8) (* X5 S9)))
 (= X9 (- (* 97 S8) (* X5 S9)))
 (= X9 (- (* X5 S8) (* 97 S9)))
 (= X9 (+ (* 97 S8) (* X6 S9)))
 (= X9 (- (* 97 S8) (* X6 S9)))
 (= X9 (- (* X6 S8) (* 97 S9)))
 (= X9 (+ (* 97 S8) (* X7 S9)))
 (= X9 (- (* 97 S8) (* X7 S9)))
 (= X9 (- (* X7 S8) (* 97 S9)))
 (= X9 (+ (* 97 S8) (* X8 S9)))
 (= X9 (- (* 97 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* 97 S9)))
 (= X9 (+ (* 493 S8) S9))
 (= X9 (- (* 493 S8) S9))
 (= X9 (- S8 (* 493 S9)))
 (= X9 (+ (* 493 S8) (* 493 S9)))
 (= X9 (- (* 493 S8) (* 493 S9)))
 (= X9 (+ (* 493 S8) (* 19 S9)))
 (= X9 (- (* 493 S8) (* 19 S9)))
 (= X9 (- (* 19 S8) (* 493 S9)))
 (= X9 (+ (* 493 S8) (* X5 S9)))
 (= X9 (- (* 493 S8) (* X5 S9)))
 (= X9 (- (* X5 S8) (* 493 S9)))
 (= X9 (+ (* 493 S8) (* X6 S9)))
 (= X9 (- (* 493 S8) (* X6 S9)))
 (= X9 (- (* X6 S8) (* 493 S9)))
 (= X9 (+ (* 493 S8) (* X7 S9)))
 (= X9 (- (* 493 S8) (* X7 S9)))
 (= X9 (- (* X7 S8) (* 493 S9)))
 (= X9 (+ (* 493 S8) (* X8 S9)))
 (= X9 (- (* 493 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* 493 S9)))
 (= X9 (+ (* 19 S8) S9))
 (= X9 (- (* 19 S8) S9))
 (= X9 (- S8 (* 19 S9)))
 (= X9 (+ (* 19 S8) (* 19 S9)))
 (= X9 (- (* 19 S8) (* 19 S9)))
 (= X9 (+ (* 19 S8) (* X5 S9)))
 (= X9 (- (* 19 S8) (* X5 S9)))
 (= X9 (- (* X5 S8) (* 19 S9)))
 (= X9 (+ (* 19 S8) (* X6 S9)))
 (= X9 (- (* 19 S8) (* X6 S9)))
 (= X9 (- (* X6 S8) (* 19 S9)))
 (= X9 (+ (* 19 S8) (* X7 S9)))
 (= X9 (- (* 19 S8) (* X7 S9)))
 (= X9 (- (* X7 S8) (* 19 S9)))
 (= X9 (+ (* 19 S8) (* X8 S9)))
 (= X9 (- (* 19 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* 19 S9)))
 (= X9 (+ (* X5 S8) S9))
 (= X9 (- (* X5 S8) S9))
 (= X9 (- S8 (* X5 S9)))
 (= X9 (+ (* X5 S8) (* X5 S9)))
 (= X9 (- (* X5 S8) (* X5 S9)))
 (= X9 (+ (* X5 S8) (* X6 S9)))
 (= X9 (- (* X5 S8) (* X6 S9)))
 (= X9 (- (* X6 S8) (* X5 S9)))
 (= X9 (+ (* X5 S8) (* X7 S9)))
 (= X9 (- (* X5 S8) (* X7 S9)))
 (= X9 (- (* X7 S8) (* X5 S9)))
 (= X9 (+ (* X5 S8) (* X8 S9)))
 (= X9 (- (* X5 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* X5 S9)))
 (= X9 (+ (* X6 S8) S9))
 (= X9 (- (* X6 S8) S9))
 (= X9 (- S8 (* X6 S9)))
 (= X9 (+ (* X6 S8) (* X6 S9)))
 (= X9 (- (* X6 S8) (* X6 S9)))
 (= X9 (+ (* X6 S8) (* X7 S9)))
 (= X9 (- (* X6 S8) (* X7 S9)))
 (= X9 (- (* X7 S8) (* X6 S9)))
 (= X9 (+ (* X6 S8) (* X8 S9)))
 (= X9 (- (* X6 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* X6 S9)))
 (= X9 (+ (* X7 S8) S9))
 (= X9 (- (* X7 S8) S9))
 (= X9 (- S8 (* X7 S9)))
 (= X9 (+ (* X7 S8) (* X7 S9)))
 (= X9 (- (* X7 S8) (* X7 S9)))
 (= X9 (+ (* X7 S8) (* X8 S9)))
 (= X9 (- (* X7 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* X7 S9)))
 (= X9 (+ (* X8 S8) S9))
 (= X9 (- (* X8 S8) S9))
 (= X9 (- S8 (* X8 S9)))
 (= X9 (+ (* X8 S8) (* X8 S9)))
 (= X9 (- (* X8 S8) (* X8 S9)))
))
(assert (and (> X9 0) (< X9 2048) (power2 S8) (power2 S9)))
(assert (or
 (= X10 (+ (* 33 S10) S11))
 (= X10 (- (* 33 S10) S11))
 (= X10 (- S10 (* 33 S11)))
 (= X10 (+ (* 33 S10) (* 33 S11)))
 (= X10 (- (* 33 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* 263 S11)))
 (= X10 (- (* 33 S10) (* 263 S11)))
 (= X10 (- (* 263 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* 97 S11)))
 (= X10 (- (* 33 S10) (* 97 S11)))
 (= X10 (- (* 97 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* 493 S11)))
 (= X10 (- (* 33 S10) (* 493 S11)))
 (= X10 (- (* 493 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* 19 S11)))
 (= X10 (- (* 33 S10) (* 19 S11)))
 (= X10 (- (* 19 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* X5 S11)))
 (= X10 (- (* 33 S10) (* X5 S11)))
 (= X10 (- (* X5 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* X6 S11)))
 (= X10 (- (* 33 S10) (* X6 S11)))
 (= X10 (- (* X6 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* X7 S11)))
 (= X10 (- (* 33 S10) (* X7 S11)))
 (= X10 (- (* X7 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* X8 S11)))
 (= X10 (- (* 33 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* 33 S11)))
 (= X10 (+ (* 33 S10) (* X9 S11)))
 (= X10 (- (* 33 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* 33 S11)))
 (= X10 (+ (* 263 S10) S11))
 (= X10 (- (* 263 S10) S11))
 (= X10 (- S10 (* 263 S11)))
 (= X10 (+ (* 263 S10) (* 263 S11)))
 (= X10 (- (* 263 S10) (* 263 S11)))
 (= X10 (+ (* 263 S10) (* 97 S11)))
 (= X10 (- (* 263 S10) (* 97 S11)))
 (= X10 (- (* 97 S10) (* 263 S11)))
 (= X10 (+ (* 263 S10) (* 493 S11)))
 (= X10 (- (* 263 S10) (* 493 S11)))
 (= X10 (- (* 493 S10) (* 263 S11)))
 (= X10 (+ (* 263 S10) (* 19 S11)))
 (= X10 (- (* 263 S10) (* 19 S11)))
 (= X10 (- (* 19 S10) (* 263 S11)))
 (= X10 (+ (* 263 S10) (* X5 S11)))
 (= X10 (- (* 263 S10) (* X5 S11)))
 (= X10 (- (* X5 S10) (* 263 S11)))
 (= X10 (+ (* 263 S10) (* X6 S11)))
 (= X10 (- (* 263 S10) (* X6 S11)))
 (= X10 (- (* X6 S10) (* 263 S11)))
 (= X10 (+ (* 263 S10) (* X7 S11)))
 (= X10 (- (* 263 S10) (* X7 S11)))
 (= X10 (- (* X7 S10) (* 263 S11)))
 (= X10 (+ (* 263 S10) (* X8 S11)))
 (= X10 (- (* 263 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* 263 S11)))
 (= X10 (+ (* 263 S10) (* X9 S11)))
 (= X10 (- (* 263 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* 263 S11)))
 (= X10 (+ (* 97 S10) S11))
 (= X10 (- (* 97 S10) S11))
 (= X10 (- S10 (* 97 S11)))
 (= X10 (+ (* 97 S10) (* 97 S11)))
 (= X10 (- (* 97 S10) (* 97 S11)))
 (= X10 (+ (* 97 S10) (* 493 S11)))
 (= X10 (- (* 97 S10) (* 493 S11)))
 (= X10 (- (* 493 S10) (* 97 S11)))
 (= X10 (+ (* 97 S10) (* 19 S11)))
 (= X10 (- (* 97 S10) (* 19 S11)))
 (= X10 (- (* 19 S10) (* 97 S11)))
 (= X10 (+ (* 97 S10) (* X5 S11)))
 (= X10 (- (* 97 S10) (* X5 S11)))
 (= X10 (- (* X5 S10) (* 97 S11)))
 (= X10 (+ (* 97 S10) (* X6 S11)))
 (= X10 (- (* 97 S10) (* X6 S11)))
 (= X10 (- (* X6 S10) (* 97 S11)))
 (= X10 (+ (* 97 S10) (* X7 S11)))
 (= X10 (- (* 97 S10) (* X7 S11)))
 (= X10 (- (* X7 S10) (* 97 S11)))
 (= X10 (+ (* 97 S10) (* X8 S11)))
 (= X10 (- (* 97 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* 97 S11)))
 (= X10 (+ (* 97 S10) (* X9 S11)))
 (= X10 (- (* 97 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* 97 S11)))
 (= X10 (+ (* 493 S10) S11))
 (= X10 (- (* 493 S10) S11))
 (= X10 (- S10 (* 493 S11)))
 (= X10 (+ (* 493 S10) (* 493 S11)))
 (= X10 (- (* 493 S10) (* 493 S11)))
 (= X10 (+ (* 493 S10) (* 19 S11)))
 (= X10 (- (* 493 S10) (* 19 S11)))
 (= X10 (- (* 19 S10) (* 493 S11)))
 (= X10 (+ (* 493 S10) (* X5 S11)))
 (= X10 (- (* 493 S10) (* X5 S11)))
 (= X10 (- (* X5 S10) (* 493 S11)))
 (= X10 (+ (* 493 S10) (* X6 S11)))
 (= X10 (- (* 493 S10) (* X6 S11)))
 (= X10 (- (* X6 S10) (* 493 S11)))
 (= X10 (+ (* 493 S10) (* X7 S11)))
 (= X10 (- (* 493 S10) (* X7 S11)))
 (= X10 (- (* X7 S10) (* 493 S11)))
 (= X10 (+ (* 493 S10) (* X8 S11)))
 (= X10 (- (* 493 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* 493 S11)))
 (= X10 (+ (* 493 S10) (* X9 S11)))
 (= X10 (- (* 493 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* 493 S11)))
 (= X10 (+ (* 19 S10) S11))
 (= X10 (- (* 19 S10) S11))
 (= X10 (- S10 (* 19 S11)))
 (= X10 (+ (* 19 S10) (* 19 S11)))
 (= X10 (- (* 19 S10) (* 19 S11)))
 (= X10 (+ (* 19 S10) (* X5 S11)))
 (= X10 (- (* 19 S10) (* X5 S11)))
 (= X10 (- (* X5 S10) (* 19 S11)))
 (= X10 (+ (* 19 S10) (* X6 S11)))
 (= X10 (- (* 19 S10) (* X6 S11)))
 (= X10 (- (* X6 S10) (* 19 S11)))
 (= X10 (+ (* 19 S10) (* X7 S11)))
 (= X10 (- (* 19 S10) (* X7 S11)))
 (= X10 (- (* X7 S10) (* 19 S11)))
 (= X10 (+ (* 19 S10) (* X8 S11)))
 (= X10 (- (* 19 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* 19 S11)))
 (= X10 (+ (* 19 S10) (* X9 S11)))
 (= X10 (- (* 19 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* 19 S11)))
 (= X10 (+ (* X5 S10) S11))
 (= X10 (- (* X5 S10) S11))
 (= X10 (- S10 (* X5 S11)))
 (= X10 (+ (* X5 S10) (* X5 S11)))
 (= X10 (- (* X5 S10) (* X5 S11)))
 (= X10 (+ (* X5 S10) (* X6 S11)))
 (= X10 (- (* X5 S10) (* X6 S11)))
 (= X10 (- (* X6 S10) (* X5 S11)))
 (= X10 (+ (* X5 S10) (* X7 S11)))
 (= X10 (- (* X5 S10) (* X7 S11)))
 (= X10 (- (* X7 S10) (* X5 S11)))
 (= X10 (+ (* X5 S10) (* X8 S11)))
 (= X10 (- (* X5 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* X5 S11)))
 (= X10 (+ (* X5 S10) (* X9 S11)))
 (= X10 (- (* X5 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* X5 S11)))
 (= X10 (+ (* X6 S10) S11))
 (= X10 (- (* X6 S10) S11))
 (= X10 (- S10 (* X6 S11)))
 (= X10 (+ (* X6 S10) (* X6 S11)))
 (= X10 (- (* X6 S10) (* X6 S11)))
 (= X10 (+ (* X6 S10) (* X7 S11)))
 (= X10 (- (* X6 S10) (* X7 S11)))
 (= X10 (- (* X7 S10) (* X6 S11)))
 (= X10 (+ (* X6 S10) (* X8 S11)))
 (= X10 (- (* X6 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* X6 S11)))
 (= X10 (+ (* X6 S10) (* X9 S11)))
 (= X10 (- (* X6 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* X6 S11)))
 (= X10 (+ (* X7 S10) S11))
 (= X10 (- (* X7 S10) S11))
 (= X10 (- S10 (* X7 S11)))
 (= X10 (+ (* X7 S10) (* X7 S11)))
 (= X10 (- (* X7 S10) (* X7 S11)))
 (= X10 (+ (* X7 S10) (* X8 S11)))
 (= X10 (- (* X7 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* X7 S11)))
 (= X10 (+ (* X7 S10) (* X9 S11)))
 (= X10 (- (* X7 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* X7 S11)))
 (= X10 (+ (* X8 S10) S11))
 (= X10 (- (* X8 S10) S11))
 (= X10 (- S10 (* X8 S11)))
 (= X10 (+ (* X8 S10) (* X8 S11)))
 (= X10 (- (* X8 S10) (* X8 S11)))
 (= X10 (+ (* X8 S10) (* X9 S11)))
 (= X10 (- (* X8 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* X8 S11)))
 (= X10 (+ (* X9 S10) S11))
 (= X10 (- (* X9 S10) S11))
 (= X10 (- S10 (* X9 S11)))
 (= X10 (+ (* X9 S10) (* X9 S11)))
 (= X10 (- (* X9 S10) (* X9 S11)))
))
(assert (and (> X10 0) (< X10 2048) (power2 S10) (power2 S11)))
(assert (or
 (= X6 771)
 (= X7 771)
 (= X8 771)
 (= X9 771)
 (= X10 771)
))
(assert (or
 (= X6 463)
 (= X7 463)
 (= X8 463)
 (= X9 463)
 (= X10 463)
))
(assert (or
 (= X6 925)
 (= X7 925)
 (= X8 925)
 (= X9 925)
 (= X10 925)
))
(assert (or
 (= X6 997)
 (= X7 997)
 (= X8 997)
 (= X9 997)
 (= X10 997)
))
(assert (or
 (= X6 53)
 (= X7 53)
 (= X8 53)
 (= X9 53)
 (= X10 53)
))
(check-sat)
(exit)
