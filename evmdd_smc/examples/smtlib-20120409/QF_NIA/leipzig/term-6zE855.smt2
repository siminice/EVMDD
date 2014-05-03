(set-logic QF_NIA)
(set-info :source |
     Constraint systems stating that a matrix interpretation is
     compatible with a rewriting system (weakly compatible with
     all rules, strictly compatible with at least one).

     Contributed by Johannes Waldmann at HTKW Leipzig.
   |)
(set-info :smt-lib-version 2.0)
(set-info :category "crafted")
(set-info :status sat)
(declare-fun n0 () Int)
(assert (>= n0 0))
(declare-fun n1 () Int)
(assert (>= n1 0))
(declare-fun n2 () Int)
(assert (>= n2 0))
(declare-fun n3 () Int)
(assert (>= n3 0))
(declare-fun n4 () Int)
(assert (>= n4 0))
(declare-fun n5 () Int)
(assert (>= n5 0))
(declare-fun n6 () Int)
(assert (>= n6 0))
(declare-fun n7 () Int)
(assert (>= n7 0))
(declare-fun n8 () Int)
(assert (= n8 (* n5 n6)))
(declare-fun n9 () Int)
(assert (= n9 (+ n4 n8)))
(declare-fun n10 () Int)
(assert (= n10 (* n5 n7)))
(declare-fun n11 () Int)
(assert (= n11 (* n7 n6)))
(declare-fun n12 () Int)
(assert (= n12 (+ n6 n11)))
(declare-fun n13 () Int)
(assert (= n13 (* n7 n7)))
(declare-fun n14 () Int)
(assert (= n14 (* n5 n4)))
(declare-fun n15 () Int)
(assert (= n15 (+ n4 n14)))
(declare-fun n16 () Int)
(assert (= n16 (* n5 n5)))
(declare-fun n17 () Int)
(assert (= n17 (* n10 n4)))
(declare-fun n18 () Int)
(assert (= n18 (+ n9 n17)))
(declare-fun n19 () Int)
(assert (= n19 (* n10 n5)))
(declare-fun n20 () Int)
(assert (= n20 (* n10 n6)))
(declare-fun n21 () Int)
(assert (= n21 (+ n9 n20)))
(declare-fun n22 () Int)
(assert (= n22 (* n10 n7)))
(declare-fun n23 () Int)
(assert (= n23 (* n1 n12)))
(declare-fun n24 () Int)
(assert (= n24 (+ n0 n23)))
(declare-fun n25 () Int)
(assert (= n25 (* n1 n13)))
(declare-fun n26 () Int)
(assert (= n26 (* n1 n6)))
(declare-fun n27 () Int)
(assert (= n27 (+ n0 n26)))
(declare-fun n28 () Int)
(assert (= n28 (* n1 n7)))
(declare-fun n29 () Int)
(assert (= n29 (* n16 n4)))
(declare-fun n30 () Int)
(assert (= n30 (+ n15 n29)))
(declare-fun n31 () Int)
(assert (= n31 (* n16 n5)))
(declare-fun n32 () Int)
(assert (= n32 (* n1 n4)))
(declare-fun n33 () Int)
(assert (= n33 (+ n0 n32)))
(declare-fun n34 () Int)
(assert (= n34 (* n1 n5)))
(declare-fun n35 () Int)
(assert (= n35 (* n10 n30)))
(declare-fun n36 () Int)
(assert (= n36 (+ n9 n35)))
(declare-fun n37 () Int)
(assert (= n37 (* n10 n31)))
(declare-fun n38 () Int)
(assert (= n38 (* n19 n9)))
(declare-fun n39 () Int)
(assert (= n39 (+ n18 n38)))
(declare-fun n40 () Int)
(assert (= n40 (* n19 n10)))
(declare-fun n41 () Int)
(assert (= n41 (* n28 n18)))
(declare-fun n42 () Int)
(assert (= n42 (+ n27 n41)))
(declare-fun n43 () Int)
(assert (= n43 (* n28 n19)))
(declare-fun n44 () Int)
(assert (= n44 (* n34 n18)))
(declare-fun n45 () Int)
(assert (= n45 (+ n33 n44)))
(declare-fun n46 () Int)
(assert (= n46 (* n34 n19)))
(declare-fun n47 () Int)
(assert (= n47 (* n10 n12)))
(declare-fun n48 () Int)
(assert (= n48 (+ n9 n47)))
(declare-fun n49 () Int)
(assert (= n49 (* n10 n13)))
(declare-fun n50 () Int)
(assert (= n50 (* n10 n36)))
(declare-fun n51 () Int)
(assert (= n51 (+ n9 n50)))
(declare-fun n52 () Int)
(assert (= n52 (* n10 n37)))
(declare-fun n53 () Int)
(assert (= n53 (* n22 n9)))
(declare-fun n54 () Int)
(assert (= n54 (+ n21 n53)))
(declare-fun n55 () Int)
(assert (= n55 (* n22 n10)))
(declare-fun n56 () Int)
(assert (= n56 (* n22 n39)))
(declare-fun n57 () Int)
(assert (= n57 (+ n21 n56)))
(declare-fun n58 () Int)
(assert (= n58 (* n22 n40)))
(declare-fun n59 () Int)
(assert (= n59 (* n5 n9)))
(declare-fun n60 () Int)
(assert (= n60 (+ n4 n59)))
(declare-fun n61 () Int)
(assert (= n61 (* n5 n10)))
(declare-fun n62 () Int)
(assert (= n62 (* n7 n21)))
(declare-fun n63 () Int)
(assert (= n63 (+ n6 n62)))
(declare-fun n64 () Int)
(assert (= n64 (* n7 n22)))
(declare-fun n65 () Int)
(assert (= n65 (* n7 n60)))
(declare-fun n66 () Int)
(assert (= n66 (+ n6 n65)))
(declare-fun n67 () Int)
(assert (= n67 (* n7 n61)))
(declare-fun n68 () Int)
(assert (= n68 (* n13 n6)))
(declare-fun n69 () Int)
(assert (= n69 (+ n12 n68)))
(declare-fun n70 () Int)
(assert (= n70 (* n13 n7)))
(declare-fun n71 () Int)
(assert (= n71 (* n13 n12)))
(declare-fun n72 () Int)
(assert (= n72 (+ n12 n71)))
(declare-fun n73 () Int)
(assert (= n73 (* n13 n13)))
(declare-fun n74 () Int)
(assert (= n74 (* n25 n6)))
(declare-fun n75 () Int)
(assert (= n75 (+ n24 n74)))
(declare-fun n76 () Int)
(assert (= n76 (* n25 n7)))
(declare-fun n77 () Int)
(assert (= n77 (* n67 n21)))
(declare-fun n78 () Int)
(assert (= n78 (+ n66 n77)))
(declare-fun n79 () Int)
(assert (= n79 (* n67 n22)))
(declare-fun n80 () Int)
(assert (= n80 (* n73 n48)))
(declare-fun n81 () Int)
(assert (= n81 (+ n72 n80)))
(declare-fun n82 () Int)
(assert (= n82 (* n73 n49)))
(declare-fun n83 () Int)
(assert (= n83 (* n1 n15)))
(declare-fun n84 () Int)
(assert (= n84 (+ n0 n83)))
(declare-fun n85 () Int)
(assert (= n85 (* n1 n16)))
(declare-fun n86 () Int)
(assert (= n86 (* n28 n4)))
(declare-fun n87 () Int)
(assert (= n87 (+ n27 n86)))
(declare-fun n88 () Int)
(assert (= n88 (* n28 n5)))
(assert (>= n87 n24))
(assert (>= n88 n25))
(declare-fun n89 () Int)
(assert (= n89 (* n25 n4)))
(declare-fun n90 () Int)
(assert (= n90 (+ n24 n89)))
(declare-fun n91 () Int)
(assert (= n91 (* n25 n5)))
(assert (>= n90 n75))
(assert (>= n91 n76))
(declare-fun n92 () Int)
(assert (= n92 (* n85 n15)))
(declare-fun n93 () Int)
(assert (= n93 (+ n84 n92)))
(declare-fun n94 () Int)
(assert (= n94 (* n85 n16)))
(declare-fun n95 () Int)
(assert (= n95 (* n34 n51)))
(declare-fun n96 () Int)
(assert (= n96 (+ n33 n95)))
(declare-fun n97 () Int)
(assert (= n97 (* n34 n52)))
(assert (>= n93 n96))
(assert (>= n94 n97))
(declare-fun n98 () Int)
(assert (= n98 (* n1 n57)))
(declare-fun n99 () Int)
(assert (= n99 (+ n0 n98)))
(declare-fun n100 () Int)
(assert (= n100 (* n1 n58)))
(assert (>= n45 n99))
(assert (>= n46 n100))
(declare-fun n101 () Int)
(assert (= n101 (* n25 n39)))
(declare-fun n102 () Int)
(assert (= n102 (+ n24 n101)))
(declare-fun n103 () Int)
(assert (= n103 (* n25 n40)))
(assert (>= n45 n102))
(assert (>= n46 n103))
(declare-fun n104 () Int)
(assert (= n104 (* n28 n60)))
(declare-fun n105 () Int)
(assert (= n105 (+ n27 n104)))
(declare-fun n106 () Int)
(assert (= n106 (* n28 n61)))
(assert (>= n45 n105))
(assert (>= n46 n106))
(declare-fun n107 () Int)
(assert (= n107 (* n25 n54)))
(declare-fun n108 () Int)
(assert (= n108 (+ n24 n107)))
(declare-fun n109 () Int)
(assert (= n109 (* n25 n55)))
(assert (>= n42 n108))
(assert (>= n43 n109))
(declare-fun n110 () Int)
(assert (= n110 (* n25 n9)))
(declare-fun n111 () Int)
(assert (= n111 (+ n24 n110)))
(declare-fun n112 () Int)
(assert (= n112 (* n25 n10)))
(assert (>= n42 n111))
(assert (>= n43 n112))
(assert (>= n42 n27))
(assert (>= n43 n28))
(declare-fun n113 () Int)
(assert (= n113 (* n76 n4)))
(declare-fun n114 () Int)
(assert (= n114 (+ n75 n113)))
(declare-fun n115 () Int)
(assert (= n115 (* n76 n5)))
(declare-fun n116 () Int)
(assert (= n116 (* n25 n12)))
(declare-fun n117 () Int)
(assert (= n117 (+ n24 n116)))
(declare-fun n118 () Int)
(assert (= n118 (* n25 n13)))
(assert (>= n114 n117))
(assert (>= n115 n118))
(declare-fun n119 () Int)
(assert (= n119 (* n13 n21)))
(declare-fun n120 () Int)
(assert (= n120 (+ n12 n119)))
(declare-fun n121 () Int)
(assert (= n121 (* n13 n22)))
(assert (>= n18 n120))
(assert (>= n19 n121))
(declare-fun n122 () Int)
(assert (= n122 (* n22 n4)))
(declare-fun n123 () Int)
(assert (= n123 (+ n21 n122)))
(declare-fun n124 () Int)
(assert (= n124 (* n22 n5)))
(declare-fun n125 () Int)
(assert (= n125 (* n70 n48)))
(declare-fun n126 () Int)
(assert (= n126 (+ n69 n125)))
(declare-fun n127 () Int)
(assert (= n127 (* n70 n49)))
(assert (>= n123 n126))
(assert (>= n124 n127))
(declare-fun n128 () Int)
(assert (= n128 (* n16 n30)))
(declare-fun n129 () Int)
(assert (= n129 (+ n15 n128)))
(declare-fun n130 () Int)
(assert (= n130 (* n16 n31)))
(declare-fun n131 () Int)
(assert (= n131 (* n16 n51)))
(declare-fun n132 () Int)
(assert (= n132 (+ n15 n131)))
(declare-fun n133 () Int)
(assert (= n133 (* n16 n52)))
(assert (>= n129 n132))
(assert (>= n130 n133))
(declare-fun n134 () Int)
(assert (= n134 (* n16 n18)))
(declare-fun n135 () Int)
(assert (= n135 (+ n15 n134)))
(declare-fun n136 () Int)
(assert (= n136 (* n16 n19)))
(declare-fun n137 () Int)
(assert (= n137 (* n5 n57)))
(declare-fun n138 () Int)
(assert (= n138 (+ n4 n137)))
(declare-fun n139 () Int)
(assert (= n139 (* n5 n58)))
(assert (>= n135 n138))
(assert (>= n136 n139))
(declare-fun n140 () Int)
(assert (= n140 (* n79 n15)))
(declare-fun n141 () Int)
(assert (= n141 (+ n78 n140)))
(declare-fun n142 () Int)
(assert (= n142 (* n79 n16)))
(assert (>= n36 n141))
(assert (>= n37 n142))
(declare-fun n143 () Int)
(assert (= n143 (* n10 n18)))
(declare-fun n144 () Int)
(assert (= n144 (+ n9 n143)))
(declare-fun n145 () Int)
(assert (= n145 (* n10 n19)))
(declare-fun n146 () Int)
(assert (= n146 (* n64 n54)))
(declare-fun n147 () Int)
(assert (= n147 (+ n63 n146)))
(declare-fun n148 () Int)
(assert (= n148 (* n64 n55)))
(assert (>= n144 n147))
(assert (>= n145 n148))
(declare-fun n149 () Int)
(assert (= n149 (* n49 n4)))
(declare-fun n150 () Int)
(assert (= n150 (+ n48 n149)))
(declare-fun n151 () Int)
(assert (= n151 (* n49 n5)))
(declare-fun n152 () Int)
(assert (= n152 (* n82 n6)))
(declare-fun n153 () Int)
(assert (= n153 (+ n81 n152)))
(declare-fun n154 () Int)
(assert (= n154 (* n82 n7)))
(assert (>= n150 n153))
(assert (>= n151 n154))
(assert (or (> n87 n24) (> n90 n75) (> n93 n96) (> n45 n99) (> n45 n102) (> n45 n105) (> n42 n108) (> n42 n111) (> n42 n27) (> n114 n117)))
(check-sat)
(exit)
