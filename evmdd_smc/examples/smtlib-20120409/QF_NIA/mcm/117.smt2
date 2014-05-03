(set-logic QF_NIA)
(set-info :source |
 more info in 'N. P. Lopes, L. Aksoy, V. Manquinho, J. Monteiro.
 Optimally Solving the MCM Problem Using Pseudo-Boolean Satisfiability.
 Technical Report RT/43/2010, INESC-ID, Nov. 2010'. |)
(declare-fun X18 () Int)
(declare-fun X19 () Int)
(declare-fun S0 () Int)
(declare-fun S1 () Int)
(declare-fun S2 () Int)
(declare-fun S3 () Int)
(define-fun power2 ((x Int)) Bool
  (or (= x 1024) (= x 512) (= x 256) (= x 128) (= x 64) (= x 32) (= x 16) (= x 8) (= x 4) (= x 2) (= x 1)))
(assert (or
 (= X18 (+ S0 S1))
 (= X18 (- S0 S1))
 (= X18 (+ (* 7 S0) S1))
 (= X18 (- (* 7 S0) S1))
 (= X18 (- S0 (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 7 S1)))
 (= X18 (- (* 7 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 25 S1)))
 (= X18 (- (* 7 S0) (* 25 S1)))
 (= X18 (- (* 25 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 23 S1)))
 (= X18 (- (* 7 S0) (* 23 S1)))
 (= X18 (- (* 23 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 113 S1)))
 (= X18 (- (* 7 S0) (* 113 S1)))
 (= X18 (- (* 113 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 99 S1)))
 (= X18 (- (* 7 S0) (* 99 S1)))
 (= X18 (- (* 99 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 399 S1)))
 (= X18 (- (* 7 S0) (* 399 S1)))
 (= X18 (- (* 399 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 233 S1)))
 (= X18 (- (* 7 S0) (* 233 S1)))
 (= X18 (- (* 233 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 911 S1)))
 (= X18 (- (* 7 S0) (* 911 S1)))
 (= X18 (- (* 911 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 67 S1)))
 (= X18 (- (* 7 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 247 S1)))
 (= X18 (- (* 7 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 37 S1)))
 (= X18 (- (* 7 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 125 S1)))
 (= X18 (- (* 7 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 1013 S1)))
 (= X18 (- (* 7 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 881 S1)))
 (= X18 (- (* 7 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 221 S1)))
 (= X18 (- (* 7 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 443 S1)))
 (= X18 (- (* 7 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 307 S1)))
 (= X18 (- (* 7 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 7 S1)))
 (= X18 (+ (* 7 S0) (* 405 S1)))
 (= X18 (- (* 7 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 7 S1)))
 (= X18 (+ (* 25 S0) S1))
 (= X18 (- (* 25 S0) S1))
 (= X18 (- S0 (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 25 S1)))
 (= X18 (- (* 25 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 23 S1)))
 (= X18 (- (* 25 S0) (* 23 S1)))
 (= X18 (- (* 23 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 113 S1)))
 (= X18 (- (* 25 S0) (* 113 S1)))
 (= X18 (- (* 113 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 99 S1)))
 (= X18 (- (* 25 S0) (* 99 S1)))
 (= X18 (- (* 99 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 399 S1)))
 (= X18 (- (* 25 S0) (* 399 S1)))
 (= X18 (- (* 399 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 233 S1)))
 (= X18 (- (* 25 S0) (* 233 S1)))
 (= X18 (- (* 233 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 911 S1)))
 (= X18 (- (* 25 S0) (* 911 S1)))
 (= X18 (- (* 911 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 67 S1)))
 (= X18 (- (* 25 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 247 S1)))
 (= X18 (- (* 25 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 37 S1)))
 (= X18 (- (* 25 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 125 S1)))
 (= X18 (- (* 25 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 1013 S1)))
 (= X18 (- (* 25 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 881 S1)))
 (= X18 (- (* 25 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 221 S1)))
 (= X18 (- (* 25 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 443 S1)))
 (= X18 (- (* 25 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 307 S1)))
 (= X18 (- (* 25 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 25 S1)))
 (= X18 (+ (* 25 S0) (* 405 S1)))
 (= X18 (- (* 25 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 25 S1)))
 (= X18 (+ (* 23 S0) S1))
 (= X18 (- (* 23 S0) S1))
 (= X18 (- S0 (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 23 S1)))
 (= X18 (- (* 23 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 113 S1)))
 (= X18 (- (* 23 S0) (* 113 S1)))
 (= X18 (- (* 113 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 99 S1)))
 (= X18 (- (* 23 S0) (* 99 S1)))
 (= X18 (- (* 99 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 399 S1)))
 (= X18 (- (* 23 S0) (* 399 S1)))
 (= X18 (- (* 399 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 233 S1)))
 (= X18 (- (* 23 S0) (* 233 S1)))
 (= X18 (- (* 233 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 911 S1)))
 (= X18 (- (* 23 S0) (* 911 S1)))
 (= X18 (- (* 911 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 67 S1)))
 (= X18 (- (* 23 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 247 S1)))
 (= X18 (- (* 23 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 37 S1)))
 (= X18 (- (* 23 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 125 S1)))
 (= X18 (- (* 23 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 1013 S1)))
 (= X18 (- (* 23 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 881 S1)))
 (= X18 (- (* 23 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 221 S1)))
 (= X18 (- (* 23 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 443 S1)))
 (= X18 (- (* 23 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 307 S1)))
 (= X18 (- (* 23 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 23 S1)))
 (= X18 (+ (* 23 S0) (* 405 S1)))
 (= X18 (- (* 23 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 23 S1)))
 (= X18 (+ (* 113 S0) S1))
 (= X18 (- (* 113 S0) S1))
 (= X18 (- S0 (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 113 S1)))
 (= X18 (- (* 113 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 99 S1)))
 (= X18 (- (* 113 S0) (* 99 S1)))
 (= X18 (- (* 99 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 399 S1)))
 (= X18 (- (* 113 S0) (* 399 S1)))
 (= X18 (- (* 399 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 233 S1)))
 (= X18 (- (* 113 S0) (* 233 S1)))
 (= X18 (- (* 233 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 911 S1)))
 (= X18 (- (* 113 S0) (* 911 S1)))
 (= X18 (- (* 911 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 67 S1)))
 (= X18 (- (* 113 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 247 S1)))
 (= X18 (- (* 113 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 37 S1)))
 (= X18 (- (* 113 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 125 S1)))
 (= X18 (- (* 113 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 1013 S1)))
 (= X18 (- (* 113 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 881 S1)))
 (= X18 (- (* 113 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 221 S1)))
 (= X18 (- (* 113 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 443 S1)))
 (= X18 (- (* 113 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 307 S1)))
 (= X18 (- (* 113 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 113 S1)))
 (= X18 (+ (* 113 S0) (* 405 S1)))
 (= X18 (- (* 113 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 113 S1)))
 (= X18 (+ (* 99 S0) S1))
 (= X18 (- (* 99 S0) S1))
 (= X18 (- S0 (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 99 S1)))
 (= X18 (- (* 99 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 399 S1)))
 (= X18 (- (* 99 S0) (* 399 S1)))
 (= X18 (- (* 399 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 233 S1)))
 (= X18 (- (* 99 S0) (* 233 S1)))
 (= X18 (- (* 233 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 911 S1)))
 (= X18 (- (* 99 S0) (* 911 S1)))
 (= X18 (- (* 911 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 67 S1)))
 (= X18 (- (* 99 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 247 S1)))
 (= X18 (- (* 99 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 37 S1)))
 (= X18 (- (* 99 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 125 S1)))
 (= X18 (- (* 99 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 1013 S1)))
 (= X18 (- (* 99 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 881 S1)))
 (= X18 (- (* 99 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 221 S1)))
 (= X18 (- (* 99 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 443 S1)))
 (= X18 (- (* 99 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 307 S1)))
 (= X18 (- (* 99 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 99 S1)))
 (= X18 (+ (* 99 S0) (* 405 S1)))
 (= X18 (- (* 99 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 99 S1)))
 (= X18 (+ (* 399 S0) S1))
 (= X18 (- (* 399 S0) S1))
 (= X18 (- S0 (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 399 S1)))
 (= X18 (- (* 399 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 233 S1)))
 (= X18 (- (* 399 S0) (* 233 S1)))
 (= X18 (- (* 233 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 911 S1)))
 (= X18 (- (* 399 S0) (* 911 S1)))
 (= X18 (- (* 911 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 67 S1)))
 (= X18 (- (* 399 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 247 S1)))
 (= X18 (- (* 399 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 37 S1)))
 (= X18 (- (* 399 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 125 S1)))
 (= X18 (- (* 399 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 1013 S1)))
 (= X18 (- (* 399 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 881 S1)))
 (= X18 (- (* 399 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 221 S1)))
 (= X18 (- (* 399 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 443 S1)))
 (= X18 (- (* 399 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 307 S1)))
 (= X18 (- (* 399 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 399 S1)))
 (= X18 (+ (* 399 S0) (* 405 S1)))
 (= X18 (- (* 399 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 399 S1)))
 (= X18 (+ (* 233 S0) S1))
 (= X18 (- (* 233 S0) S1))
 (= X18 (- S0 (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 233 S1)))
 (= X18 (- (* 233 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 911 S1)))
 (= X18 (- (* 233 S0) (* 911 S1)))
 (= X18 (- (* 911 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 67 S1)))
 (= X18 (- (* 233 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 247 S1)))
 (= X18 (- (* 233 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 37 S1)))
 (= X18 (- (* 233 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 125 S1)))
 (= X18 (- (* 233 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 1013 S1)))
 (= X18 (- (* 233 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 881 S1)))
 (= X18 (- (* 233 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 221 S1)))
 (= X18 (- (* 233 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 443 S1)))
 (= X18 (- (* 233 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 307 S1)))
 (= X18 (- (* 233 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 233 S1)))
 (= X18 (+ (* 233 S0) (* 405 S1)))
 (= X18 (- (* 233 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 233 S1)))
 (= X18 (+ (* 911 S0) S1))
 (= X18 (- (* 911 S0) S1))
 (= X18 (- S0 (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 911 S1)))
 (= X18 (- (* 911 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 67 S1)))
 (= X18 (- (* 911 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 247 S1)))
 (= X18 (- (* 911 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 37 S1)))
 (= X18 (- (* 911 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 125 S1)))
 (= X18 (- (* 911 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 1013 S1)))
 (= X18 (- (* 911 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 881 S1)))
 (= X18 (- (* 911 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 221 S1)))
 (= X18 (- (* 911 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 443 S1)))
 (= X18 (- (* 911 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 307 S1)))
 (= X18 (- (* 911 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 911 S1)))
 (= X18 (+ (* 911 S0) (* 405 S1)))
 (= X18 (- (* 911 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 911 S1)))
 (= X18 (+ (* 67 S0) S1))
 (= X18 (- (* 67 S0) S1))
 (= X18 (- S0 (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 67 S1)))
 (= X18 (- (* 67 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 247 S1)))
 (= X18 (- (* 67 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 37 S1)))
 (= X18 (- (* 67 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 125 S1)))
 (= X18 (- (* 67 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 1013 S1)))
 (= X18 (- (* 67 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 881 S1)))
 (= X18 (- (* 67 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 221 S1)))
 (= X18 (- (* 67 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 443 S1)))
 (= X18 (- (* 67 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 307 S1)))
 (= X18 (- (* 67 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 67 S1)))
 (= X18 (+ (* 67 S0) (* 405 S1)))
 (= X18 (- (* 67 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 67 S1)))
 (= X18 (+ (* 247 S0) S1))
 (= X18 (- (* 247 S0) S1))
 (= X18 (- S0 (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 247 S1)))
 (= X18 (- (* 247 S0) (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 37 S1)))
 (= X18 (- (* 247 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 125 S1)))
 (= X18 (- (* 247 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 1013 S1)))
 (= X18 (- (* 247 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 881 S1)))
 (= X18 (- (* 247 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 221 S1)))
 (= X18 (- (* 247 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 443 S1)))
 (= X18 (- (* 247 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 307 S1)))
 (= X18 (- (* 247 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 247 S1)))
 (= X18 (+ (* 247 S0) (* 405 S1)))
 (= X18 (- (* 247 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 247 S1)))
 (= X18 (+ (* 37 S0) S1))
 (= X18 (- (* 37 S0) S1))
 (= X18 (- S0 (* 37 S1)))
 (= X18 (+ (* 37 S0) (* 37 S1)))
 (= X18 (- (* 37 S0) (* 37 S1)))
 (= X18 (+ (* 37 S0) (* 125 S1)))
 (= X18 (- (* 37 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 37 S1)))
 (= X18 (+ (* 37 S0) (* 1013 S1)))
 (= X18 (- (* 37 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 37 S1)))
 (= X18 (+ (* 37 S0) (* 881 S1)))
 (= X18 (- (* 37 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 37 S1)))
 (= X18 (+ (* 37 S0) (* 221 S1)))
 (= X18 (- (* 37 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 37 S1)))
 (= X18 (+ (* 37 S0) (* 443 S1)))
 (= X18 (- (* 37 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 37 S1)))
 (= X18 (+ (* 37 S0) (* 307 S1)))
 (= X18 (- (* 37 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 37 S1)))
 (= X18 (+ (* 37 S0) (* 405 S1)))
 (= X18 (- (* 37 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 37 S1)))
 (= X18 (+ (* 125 S0) S1))
 (= X18 (- (* 125 S0) S1))
 (= X18 (- S0 (* 125 S1)))
 (= X18 (+ (* 125 S0) (* 125 S1)))
 (= X18 (- (* 125 S0) (* 125 S1)))
 (= X18 (+ (* 125 S0) (* 1013 S1)))
 (= X18 (- (* 125 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 125 S1)))
 (= X18 (+ (* 125 S0) (* 881 S1)))
 (= X18 (- (* 125 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 125 S1)))
 (= X18 (+ (* 125 S0) (* 221 S1)))
 (= X18 (- (* 125 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 125 S1)))
 (= X18 (+ (* 125 S0) (* 443 S1)))
 (= X18 (- (* 125 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 125 S1)))
 (= X18 (+ (* 125 S0) (* 307 S1)))
 (= X18 (- (* 125 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 125 S1)))
 (= X18 (+ (* 125 S0) (* 405 S1)))
 (= X18 (- (* 125 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 125 S1)))
 (= X18 (+ (* 1013 S0) S1))
 (= X18 (- (* 1013 S0) S1))
 (= X18 (- S0 (* 1013 S1)))
 (= X18 (+ (* 1013 S0) (* 1013 S1)))
 (= X18 (- (* 1013 S0) (* 1013 S1)))
 (= X18 (+ (* 1013 S0) (* 881 S1)))
 (= X18 (- (* 1013 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 1013 S1)))
 (= X18 (+ (* 1013 S0) (* 221 S1)))
 (= X18 (- (* 1013 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 1013 S1)))
 (= X18 (+ (* 1013 S0) (* 443 S1)))
 (= X18 (- (* 1013 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 1013 S1)))
 (= X18 (+ (* 1013 S0) (* 307 S1)))
 (= X18 (- (* 1013 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 1013 S1)))
 (= X18 (+ (* 1013 S0) (* 405 S1)))
 (= X18 (- (* 1013 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 1013 S1)))
 (= X18 (+ (* 881 S0) S1))
 (= X18 (- (* 881 S0) S1))
 (= X18 (- S0 (* 881 S1)))
 (= X18 (+ (* 881 S0) (* 881 S1)))
 (= X18 (- (* 881 S0) (* 881 S1)))
 (= X18 (+ (* 881 S0) (* 221 S1)))
 (= X18 (- (* 881 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 881 S1)))
 (= X18 (+ (* 881 S0) (* 443 S1)))
 (= X18 (- (* 881 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 881 S1)))
 (= X18 (+ (* 881 S0) (* 307 S1)))
 (= X18 (- (* 881 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 881 S1)))
 (= X18 (+ (* 881 S0) (* 405 S1)))
 (= X18 (- (* 881 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 881 S1)))
 (= X18 (+ (* 221 S0) S1))
 (= X18 (- (* 221 S0) S1))
 (= X18 (- S0 (* 221 S1)))
 (= X18 (+ (* 221 S0) (* 221 S1)))
 (= X18 (- (* 221 S0) (* 221 S1)))
 (= X18 (+ (* 221 S0) (* 443 S1)))
 (= X18 (- (* 221 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 221 S1)))
 (= X18 (+ (* 221 S0) (* 307 S1)))
 (= X18 (- (* 221 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 221 S1)))
 (= X18 (+ (* 221 S0) (* 405 S1)))
 (= X18 (- (* 221 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 221 S1)))
 (= X18 (+ (* 443 S0) S1))
 (= X18 (- (* 443 S0) S1))
 (= X18 (- S0 (* 443 S1)))
 (= X18 (+ (* 443 S0) (* 443 S1)))
 (= X18 (- (* 443 S0) (* 443 S1)))
 (= X18 (+ (* 443 S0) (* 307 S1)))
 (= X18 (- (* 443 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 443 S1)))
 (= X18 (+ (* 443 S0) (* 405 S1)))
 (= X18 (- (* 443 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 443 S1)))
 (= X18 (+ (* 307 S0) S1))
 (= X18 (- (* 307 S0) S1))
 (= X18 (- S0 (* 307 S1)))
 (= X18 (+ (* 307 S0) (* 307 S1)))
 (= X18 (- (* 307 S0) (* 307 S1)))
 (= X18 (+ (* 307 S0) (* 405 S1)))
 (= X18 (- (* 307 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 307 S1)))
 (= X18 (+ (* 405 S0) S1))
 (= X18 (- (* 405 S0) S1))
 (= X18 (- S0 (* 405 S1)))
 (= X18 (+ (* 405 S0) (* 405 S1)))
 (= X18 (- (* 405 S0) (* 405 S1)))
))
(assert (and (> X18 0) (< X18 2048) (power2 S0) (power2 S1)))
(assert (or
 (= X19 (+ (* 7 S2) S3))
 (= X19 (- (* 7 S2) S3))
 (= X19 (- S2 (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 7 S3)))
 (= X19 (- (* 7 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 25 S3)))
 (= X19 (- (* 7 S2) (* 25 S3)))
 (= X19 (- (* 25 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 23 S3)))
 (= X19 (- (* 7 S2) (* 23 S3)))
 (= X19 (- (* 23 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 113 S3)))
 (= X19 (- (* 7 S2) (* 113 S3)))
 (= X19 (- (* 113 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 99 S3)))
 (= X19 (- (* 7 S2) (* 99 S3)))
 (= X19 (- (* 99 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 399 S3)))
 (= X19 (- (* 7 S2) (* 399 S3)))
 (= X19 (- (* 399 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 233 S3)))
 (= X19 (- (* 7 S2) (* 233 S3)))
 (= X19 (- (* 233 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 911 S3)))
 (= X19 (- (* 7 S2) (* 911 S3)))
 (= X19 (- (* 911 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 67 S3)))
 (= X19 (- (* 7 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 247 S3)))
 (= X19 (- (* 7 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 37 S3)))
 (= X19 (- (* 7 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 125 S3)))
 (= X19 (- (* 7 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 1013 S3)))
 (= X19 (- (* 7 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 881 S3)))
 (= X19 (- (* 7 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 221 S3)))
 (= X19 (- (* 7 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 443 S3)))
 (= X19 (- (* 7 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 307 S3)))
 (= X19 (- (* 7 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* 405 S3)))
 (= X19 (- (* 7 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 7 S3)))
 (= X19 (+ (* 7 S2) (* X18 S3)))
 (= X19 (- (* 7 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 7 S3)))
 (= X19 (+ (* 25 S2) S3))
 (= X19 (- (* 25 S2) S3))
 (= X19 (- S2 (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 25 S3)))
 (= X19 (- (* 25 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 23 S3)))
 (= X19 (- (* 25 S2) (* 23 S3)))
 (= X19 (- (* 23 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 113 S3)))
 (= X19 (- (* 25 S2) (* 113 S3)))
 (= X19 (- (* 113 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 99 S3)))
 (= X19 (- (* 25 S2) (* 99 S3)))
 (= X19 (- (* 99 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 399 S3)))
 (= X19 (- (* 25 S2) (* 399 S3)))
 (= X19 (- (* 399 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 233 S3)))
 (= X19 (- (* 25 S2) (* 233 S3)))
 (= X19 (- (* 233 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 911 S3)))
 (= X19 (- (* 25 S2) (* 911 S3)))
 (= X19 (- (* 911 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 67 S3)))
 (= X19 (- (* 25 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 247 S3)))
 (= X19 (- (* 25 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 37 S3)))
 (= X19 (- (* 25 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 125 S3)))
 (= X19 (- (* 25 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 1013 S3)))
 (= X19 (- (* 25 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 881 S3)))
 (= X19 (- (* 25 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 221 S3)))
 (= X19 (- (* 25 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 443 S3)))
 (= X19 (- (* 25 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 307 S3)))
 (= X19 (- (* 25 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* 405 S3)))
 (= X19 (- (* 25 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 25 S3)))
 (= X19 (+ (* 25 S2) (* X18 S3)))
 (= X19 (- (* 25 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 25 S3)))
 (= X19 (+ (* 23 S2) S3))
 (= X19 (- (* 23 S2) S3))
 (= X19 (- S2 (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 23 S3)))
 (= X19 (- (* 23 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 113 S3)))
 (= X19 (- (* 23 S2) (* 113 S3)))
 (= X19 (- (* 113 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 99 S3)))
 (= X19 (- (* 23 S2) (* 99 S3)))
 (= X19 (- (* 99 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 399 S3)))
 (= X19 (- (* 23 S2) (* 399 S3)))
 (= X19 (- (* 399 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 233 S3)))
 (= X19 (- (* 23 S2) (* 233 S3)))
 (= X19 (- (* 233 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 911 S3)))
 (= X19 (- (* 23 S2) (* 911 S3)))
 (= X19 (- (* 911 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 67 S3)))
 (= X19 (- (* 23 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 247 S3)))
 (= X19 (- (* 23 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 37 S3)))
 (= X19 (- (* 23 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 125 S3)))
 (= X19 (- (* 23 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 1013 S3)))
 (= X19 (- (* 23 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 881 S3)))
 (= X19 (- (* 23 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 221 S3)))
 (= X19 (- (* 23 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 443 S3)))
 (= X19 (- (* 23 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 307 S3)))
 (= X19 (- (* 23 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* 405 S3)))
 (= X19 (- (* 23 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 23 S3)))
 (= X19 (+ (* 23 S2) (* X18 S3)))
 (= X19 (- (* 23 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 23 S3)))
 (= X19 (+ (* 113 S2) S3))
 (= X19 (- (* 113 S2) S3))
 (= X19 (- S2 (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 113 S3)))
 (= X19 (- (* 113 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 99 S3)))
 (= X19 (- (* 113 S2) (* 99 S3)))
 (= X19 (- (* 99 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 399 S3)))
 (= X19 (- (* 113 S2) (* 399 S3)))
 (= X19 (- (* 399 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 233 S3)))
 (= X19 (- (* 113 S2) (* 233 S3)))
 (= X19 (- (* 233 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 911 S3)))
 (= X19 (- (* 113 S2) (* 911 S3)))
 (= X19 (- (* 911 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 67 S3)))
 (= X19 (- (* 113 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 247 S3)))
 (= X19 (- (* 113 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 37 S3)))
 (= X19 (- (* 113 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 125 S3)))
 (= X19 (- (* 113 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 1013 S3)))
 (= X19 (- (* 113 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 881 S3)))
 (= X19 (- (* 113 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 221 S3)))
 (= X19 (- (* 113 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 443 S3)))
 (= X19 (- (* 113 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 307 S3)))
 (= X19 (- (* 113 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* 405 S3)))
 (= X19 (- (* 113 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 113 S3)))
 (= X19 (+ (* 113 S2) (* X18 S3)))
 (= X19 (- (* 113 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 113 S3)))
 (= X19 (+ (* 99 S2) S3))
 (= X19 (- (* 99 S2) S3))
 (= X19 (- S2 (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 99 S3)))
 (= X19 (- (* 99 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 399 S3)))
 (= X19 (- (* 99 S2) (* 399 S3)))
 (= X19 (- (* 399 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 233 S3)))
 (= X19 (- (* 99 S2) (* 233 S3)))
 (= X19 (- (* 233 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 911 S3)))
 (= X19 (- (* 99 S2) (* 911 S3)))
 (= X19 (- (* 911 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 67 S3)))
 (= X19 (- (* 99 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 247 S3)))
 (= X19 (- (* 99 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 37 S3)))
 (= X19 (- (* 99 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 125 S3)))
 (= X19 (- (* 99 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 1013 S3)))
 (= X19 (- (* 99 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 881 S3)))
 (= X19 (- (* 99 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 221 S3)))
 (= X19 (- (* 99 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 443 S3)))
 (= X19 (- (* 99 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 307 S3)))
 (= X19 (- (* 99 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* 405 S3)))
 (= X19 (- (* 99 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 99 S3)))
 (= X19 (+ (* 99 S2) (* X18 S3)))
 (= X19 (- (* 99 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 99 S3)))
 (= X19 (+ (* 399 S2) S3))
 (= X19 (- (* 399 S2) S3))
 (= X19 (- S2 (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 399 S3)))
 (= X19 (- (* 399 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 233 S3)))
 (= X19 (- (* 399 S2) (* 233 S3)))
 (= X19 (- (* 233 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 911 S3)))
 (= X19 (- (* 399 S2) (* 911 S3)))
 (= X19 (- (* 911 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 67 S3)))
 (= X19 (- (* 399 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 247 S3)))
 (= X19 (- (* 399 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 37 S3)))
 (= X19 (- (* 399 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 125 S3)))
 (= X19 (- (* 399 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 1013 S3)))
 (= X19 (- (* 399 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 881 S3)))
 (= X19 (- (* 399 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 221 S3)))
 (= X19 (- (* 399 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 443 S3)))
 (= X19 (- (* 399 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 307 S3)))
 (= X19 (- (* 399 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* 405 S3)))
 (= X19 (- (* 399 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 399 S3)))
 (= X19 (+ (* 399 S2) (* X18 S3)))
 (= X19 (- (* 399 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 399 S3)))
 (= X19 (+ (* 233 S2) S3))
 (= X19 (- (* 233 S2) S3))
 (= X19 (- S2 (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 233 S3)))
 (= X19 (- (* 233 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 911 S3)))
 (= X19 (- (* 233 S2) (* 911 S3)))
 (= X19 (- (* 911 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 67 S3)))
 (= X19 (- (* 233 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 247 S3)))
 (= X19 (- (* 233 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 37 S3)))
 (= X19 (- (* 233 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 125 S3)))
 (= X19 (- (* 233 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 1013 S3)))
 (= X19 (- (* 233 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 881 S3)))
 (= X19 (- (* 233 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 221 S3)))
 (= X19 (- (* 233 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 443 S3)))
 (= X19 (- (* 233 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 307 S3)))
 (= X19 (- (* 233 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* 405 S3)))
 (= X19 (- (* 233 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 233 S3)))
 (= X19 (+ (* 233 S2) (* X18 S3)))
 (= X19 (- (* 233 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 233 S3)))
 (= X19 (+ (* 911 S2) S3))
 (= X19 (- (* 911 S2) S3))
 (= X19 (- S2 (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 911 S3)))
 (= X19 (- (* 911 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 67 S3)))
 (= X19 (- (* 911 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 247 S3)))
 (= X19 (- (* 911 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 37 S3)))
 (= X19 (- (* 911 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 125 S3)))
 (= X19 (- (* 911 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 1013 S3)))
 (= X19 (- (* 911 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 881 S3)))
 (= X19 (- (* 911 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 221 S3)))
 (= X19 (- (* 911 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 443 S3)))
 (= X19 (- (* 911 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 307 S3)))
 (= X19 (- (* 911 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* 405 S3)))
 (= X19 (- (* 911 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 911 S3)))
 (= X19 (+ (* 911 S2) (* X18 S3)))
 (= X19 (- (* 911 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 911 S3)))
 (= X19 (+ (* 67 S2) S3))
 (= X19 (- (* 67 S2) S3))
 (= X19 (- S2 (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 67 S3)))
 (= X19 (- (* 67 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 247 S3)))
 (= X19 (- (* 67 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 37 S3)))
 (= X19 (- (* 67 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 125 S3)))
 (= X19 (- (* 67 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 1013 S3)))
 (= X19 (- (* 67 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 881 S3)))
 (= X19 (- (* 67 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 221 S3)))
 (= X19 (- (* 67 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 443 S3)))
 (= X19 (- (* 67 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 307 S3)))
 (= X19 (- (* 67 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* 405 S3)))
 (= X19 (- (* 67 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 67 S3)))
 (= X19 (+ (* 67 S2) (* X18 S3)))
 (= X19 (- (* 67 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 67 S3)))
 (= X19 (+ (* 247 S2) S3))
 (= X19 (- (* 247 S2) S3))
 (= X19 (- S2 (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 247 S3)))
 (= X19 (- (* 247 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 37 S3)))
 (= X19 (- (* 247 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 125 S3)))
 (= X19 (- (* 247 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 1013 S3)))
 (= X19 (- (* 247 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 881 S3)))
 (= X19 (- (* 247 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 221 S3)))
 (= X19 (- (* 247 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 443 S3)))
 (= X19 (- (* 247 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 307 S3)))
 (= X19 (- (* 247 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* 405 S3)))
 (= X19 (- (* 247 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 247 S3)))
 (= X19 (+ (* 247 S2) (* X18 S3)))
 (= X19 (- (* 247 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 247 S3)))
 (= X19 (+ (* 37 S2) S3))
 (= X19 (- (* 37 S2) S3))
 (= X19 (- S2 (* 37 S3)))
 (= X19 (+ (* 37 S2) (* 37 S3)))
 (= X19 (- (* 37 S2) (* 37 S3)))
 (= X19 (+ (* 37 S2) (* 125 S3)))
 (= X19 (- (* 37 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 37 S3)))
 (= X19 (+ (* 37 S2) (* 1013 S3)))
 (= X19 (- (* 37 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 37 S3)))
 (= X19 (+ (* 37 S2) (* 881 S3)))
 (= X19 (- (* 37 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 37 S3)))
 (= X19 (+ (* 37 S2) (* 221 S3)))
 (= X19 (- (* 37 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 37 S3)))
 (= X19 (+ (* 37 S2) (* 443 S3)))
 (= X19 (- (* 37 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 37 S3)))
 (= X19 (+ (* 37 S2) (* 307 S3)))
 (= X19 (- (* 37 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 37 S3)))
 (= X19 (+ (* 37 S2) (* 405 S3)))
 (= X19 (- (* 37 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 37 S3)))
 (= X19 (+ (* 37 S2) (* X18 S3)))
 (= X19 (- (* 37 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 37 S3)))
 (= X19 (+ (* 125 S2) S3))
 (= X19 (- (* 125 S2) S3))
 (= X19 (- S2 (* 125 S3)))
 (= X19 (+ (* 125 S2) (* 125 S3)))
 (= X19 (- (* 125 S2) (* 125 S3)))
 (= X19 (+ (* 125 S2) (* 1013 S3)))
 (= X19 (- (* 125 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 125 S3)))
 (= X19 (+ (* 125 S2) (* 881 S3)))
 (= X19 (- (* 125 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 125 S3)))
 (= X19 (+ (* 125 S2) (* 221 S3)))
 (= X19 (- (* 125 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 125 S3)))
 (= X19 (+ (* 125 S2) (* 443 S3)))
 (= X19 (- (* 125 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 125 S3)))
 (= X19 (+ (* 125 S2) (* 307 S3)))
 (= X19 (- (* 125 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 125 S3)))
 (= X19 (+ (* 125 S2) (* 405 S3)))
 (= X19 (- (* 125 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 125 S3)))
 (= X19 (+ (* 125 S2) (* X18 S3)))
 (= X19 (- (* 125 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 125 S3)))
 (= X19 (+ (* 1013 S2) S3))
 (= X19 (- (* 1013 S2) S3))
 (= X19 (- S2 (* 1013 S3)))
 (= X19 (+ (* 1013 S2) (* 1013 S3)))
 (= X19 (- (* 1013 S2) (* 1013 S3)))
 (= X19 (+ (* 1013 S2) (* 881 S3)))
 (= X19 (- (* 1013 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 1013 S3)))
 (= X19 (+ (* 1013 S2) (* 221 S3)))
 (= X19 (- (* 1013 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 1013 S3)))
 (= X19 (+ (* 1013 S2) (* 443 S3)))
 (= X19 (- (* 1013 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 1013 S3)))
 (= X19 (+ (* 1013 S2) (* 307 S3)))
 (= X19 (- (* 1013 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 1013 S3)))
 (= X19 (+ (* 1013 S2) (* 405 S3)))
 (= X19 (- (* 1013 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 1013 S3)))
 (= X19 (+ (* 1013 S2) (* X18 S3)))
 (= X19 (- (* 1013 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 1013 S3)))
 (= X19 (+ (* 881 S2) S3))
 (= X19 (- (* 881 S2) S3))
 (= X19 (- S2 (* 881 S3)))
 (= X19 (+ (* 881 S2) (* 881 S3)))
 (= X19 (- (* 881 S2) (* 881 S3)))
 (= X19 (+ (* 881 S2) (* 221 S3)))
 (= X19 (- (* 881 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 881 S3)))
 (= X19 (+ (* 881 S2) (* 443 S3)))
 (= X19 (- (* 881 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 881 S3)))
 (= X19 (+ (* 881 S2) (* 307 S3)))
 (= X19 (- (* 881 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 881 S3)))
 (= X19 (+ (* 881 S2) (* 405 S3)))
 (= X19 (- (* 881 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 881 S3)))
 (= X19 (+ (* 881 S2) (* X18 S3)))
 (= X19 (- (* 881 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 881 S3)))
 (= X19 (+ (* 221 S2) S3))
 (= X19 (- (* 221 S2) S3))
 (= X19 (- S2 (* 221 S3)))
 (= X19 (+ (* 221 S2) (* 221 S3)))
 (= X19 (- (* 221 S2) (* 221 S3)))
 (= X19 (+ (* 221 S2) (* 443 S3)))
 (= X19 (- (* 221 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 221 S3)))
 (= X19 (+ (* 221 S2) (* 307 S3)))
 (= X19 (- (* 221 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 221 S3)))
 (= X19 (+ (* 221 S2) (* 405 S3)))
 (= X19 (- (* 221 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 221 S3)))
 (= X19 (+ (* 221 S2) (* X18 S3)))
 (= X19 (- (* 221 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 221 S3)))
 (= X19 (+ (* 443 S2) S3))
 (= X19 (- (* 443 S2) S3))
 (= X19 (- S2 (* 443 S3)))
 (= X19 (+ (* 443 S2) (* 443 S3)))
 (= X19 (- (* 443 S2) (* 443 S3)))
 (= X19 (+ (* 443 S2) (* 307 S3)))
 (= X19 (- (* 443 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 443 S3)))
 (= X19 (+ (* 443 S2) (* 405 S3)))
 (= X19 (- (* 443 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 443 S3)))
 (= X19 (+ (* 443 S2) (* X18 S3)))
 (= X19 (- (* 443 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 443 S3)))
 (= X19 (+ (* 307 S2) S3))
 (= X19 (- (* 307 S2) S3))
 (= X19 (- S2 (* 307 S3)))
 (= X19 (+ (* 307 S2) (* 307 S3)))
 (= X19 (- (* 307 S2) (* 307 S3)))
 (= X19 (+ (* 307 S2) (* 405 S3)))
 (= X19 (- (* 307 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 307 S3)))
 (= X19 (+ (* 307 S2) (* X18 S3)))
 (= X19 (- (* 307 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 307 S3)))
 (= X19 (+ (* 405 S2) S3))
 (= X19 (- (* 405 S2) S3))
 (= X19 (- S2 (* 405 S3)))
 (= X19 (+ (* 405 S2) (* 405 S3)))
 (= X19 (- (* 405 S2) (* 405 S3)))
 (= X19 (+ (* 405 S2) (* X18 S3)))
 (= X19 (- (* 405 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* 405 S3)))
 (= X19 (+ (* X18 S2) S3))
 (= X19 (- (* X18 S2) S3))
 (= X19 (- S2 (* X18 S3)))
 (= X19 (+ (* X18 S2) (* X18 S3)))
 (= X19 (- (* X18 S2) (* X18 S3)))
))
(assert (and (> X19 0) (< X19 2048) (power2 S2) (power2 S3)))
(assert
 (= X19 723)
)
(check-sat)
(exit)
