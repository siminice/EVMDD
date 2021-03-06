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
(assert (>= n8 0))
(declare-fun n9 () Int)
(assert (>= n9 0))
(declare-fun n10 () Int)
(assert (>= n10 0))
(declare-fun n11 () Int)
(assert (>= n11 0))
(declare-fun n12 () Int)
(assert (>= n12 0))
(declare-fun n13 () Int)
(assert (>= n13 0))
(declare-fun n14 () Int)
(assert (>= n14 0))
(declare-fun n15 () Int)
(assert (>= n15 0))
(declare-fun n16 () Int)
(assert (>= n16 0))
(declare-fun n17 () Int)
(assert (>= n17 0))
(declare-fun n18 () Int)
(assert (= n18 (* n14 n6)))
(declare-fun n19 () Int)
(assert (= n19 (* n15 n7)))
(declare-fun n20 () Int)
(assert (= n20 (* n16 n6)))
(declare-fun n21 () Int)
(assert (= n21 (* n17 n7)))
(declare-fun n22 () Int)
(assert (= n22 (+ n18 n19)))
(declare-fun n23 () Int)
(assert (= n23 (+ n20 n21)))
(declare-fun n24 () Int)
(assert (= n24 (+ n12 n22)))
(declare-fun n25 () Int)
(assert (= n25 (+ n13 n23)))
(declare-fun n26 () Int)
(assert (= n26 (* n14 n8)))
(declare-fun n27 () Int)
(assert (= n27 (* n15 n10)))
(declare-fun n28 () Int)
(assert (= n28 (* n14 n9)))
(declare-fun n29 () Int)
(assert (= n29 (* n15 n11)))
(declare-fun n30 () Int)
(assert (= n30 (* n16 n8)))
(declare-fun n31 () Int)
(assert (= n31 (* n17 n10)))
(declare-fun n32 () Int)
(assert (= n32 (* n16 n9)))
(declare-fun n33 () Int)
(assert (= n33 (* n17 n11)))
(declare-fun n34 () Int)
(assert (= n34 (+ n26 n27)))
(declare-fun n35 () Int)
(assert (= n35 (+ n28 n29)))
(declare-fun n36 () Int)
(assert (= n36 (+ n30 n31)))
(declare-fun n37 () Int)
(assert (= n37 (+ n32 n33)))
(declare-fun n38 () Int)
(assert (= n38 (* n14 n12)))
(declare-fun n39 () Int)
(assert (= n39 (* n15 n13)))
(declare-fun n40 () Int)
(assert (= n40 (* n16 n12)))
(declare-fun n41 () Int)
(assert (= n41 (* n17 n13)))
(declare-fun n42 () Int)
(assert (= n42 (+ n38 n39)))
(declare-fun n43 () Int)
(assert (= n43 (+ n40 n41)))
(declare-fun n44 () Int)
(assert (= n44 (+ n12 n42)))
(declare-fun n45 () Int)
(assert (= n45 (+ n13 n43)))
(declare-fun n46 () Int)
(assert (= n46 (* n14 n14)))
(declare-fun n47 () Int)
(assert (= n47 (* n15 n16)))
(declare-fun n48 () Int)
(assert (= n48 (* n14 n15)))
(declare-fun n49 () Int)
(assert (= n49 (* n15 n17)))
(declare-fun n50 () Int)
(assert (= n50 (* n16 n14)))
(declare-fun n51 () Int)
(assert (= n51 (* n17 n16)))
(declare-fun n52 () Int)
(assert (= n52 (* n16 n15)))
(declare-fun n53 () Int)
(assert (= n53 (* n17 n17)))
(declare-fun n54 () Int)
(assert (= n54 (+ n46 n47)))
(declare-fun n55 () Int)
(assert (= n55 (+ n48 n49)))
(declare-fun n56 () Int)
(assert (= n56 (+ n50 n51)))
(declare-fun n57 () Int)
(assert (= n57 (+ n52 n53)))
(declare-fun n58 () Int)
(assert (= n58 (* n14 n24)))
(declare-fun n59 () Int)
(assert (= n59 (* n15 n25)))
(declare-fun n60 () Int)
(assert (= n60 (* n16 n24)))
(declare-fun n61 () Int)
(assert (= n61 (* n17 n25)))
(declare-fun n62 () Int)
(assert (= n62 (+ n58 n59)))
(declare-fun n63 () Int)
(assert (= n63 (+ n60 n61)))
(declare-fun n64 () Int)
(assert (= n64 (+ n12 n62)))
(declare-fun n65 () Int)
(assert (= n65 (+ n13 n63)))
(declare-fun n66 () Int)
(assert (= n66 (* n14 n34)))
(declare-fun n67 () Int)
(assert (= n67 (* n15 n36)))
(declare-fun n68 () Int)
(assert (= n68 (* n14 n35)))
(declare-fun n69 () Int)
(assert (= n69 (* n15 n37)))
(declare-fun n70 () Int)
(assert (= n70 (* n16 n34)))
(declare-fun n71 () Int)
(assert (= n71 (* n17 n36)))
(declare-fun n72 () Int)
(assert (= n72 (* n16 n35)))
(declare-fun n73 () Int)
(assert (= n73 (* n17 n37)))
(declare-fun n74 () Int)
(assert (= n74 (+ n66 n67)))
(declare-fun n75 () Int)
(assert (= n75 (+ n68 n69)))
(declare-fun n76 () Int)
(assert (= n76 (+ n70 n71)))
(declare-fun n77 () Int)
(assert (= n77 (+ n72 n73)))
(declare-fun n78 () Int)
(assert (= n78 (* n1 n24)))
(declare-fun n79 () Int)
(assert (= n79 (* n2 n25)))
(declare-fun n80 () Int)
(assert (= n80 (+ n78 n79)))
(declare-fun n81 () Int)
(assert (= n81 (+ n0 n80)))
(declare-fun n82 () Int)
(assert (= n82 (* n1 n34)))
(declare-fun n83 () Int)
(assert (= n83 (* n2 n36)))
(declare-fun n84 () Int)
(assert (= n84 (* n1 n35)))
(declare-fun n85 () Int)
(assert (= n85 (* n2 n37)))
(declare-fun n86 () Int)
(assert (= n86 (+ n82 n83)))
(declare-fun n87 () Int)
(assert (= n87 (+ n84 n85)))
(declare-fun n88 () Int)
(assert (= n88 (* n1 n64)))
(declare-fun n89 () Int)
(assert (= n89 (* n2 n65)))
(declare-fun n90 () Int)
(assert (= n90 (+ n88 n89)))
(declare-fun n91 () Int)
(assert (= n91 (+ n0 n90)))
(declare-fun n92 () Int)
(assert (= n92 (* n1 n74)))
(declare-fun n93 () Int)
(assert (= n93 (* n2 n76)))
(declare-fun n94 () Int)
(assert (= n94 (* n1 n75)))
(declare-fun n95 () Int)
(assert (= n95 (* n2 n77)))
(declare-fun n96 () Int)
(assert (= n96 (+ n92 n93)))
(declare-fun n97 () Int)
(assert (= n97 (+ n94 n95)))
(assert (>= n81 n91))
(assert (>= n86 n96))
(assert (>= n87 n97))
(declare-fun n98 () Int)
(assert (= n98 (* n8 n24)))
(declare-fun n99 () Int)
(assert (= n99 (* n9 n25)))
(declare-fun n100 () Int)
(assert (= n100 (* n10 n24)))
(declare-fun n101 () Int)
(assert (= n101 (* n11 n25)))
(declare-fun n102 () Int)
(assert (= n102 (+ n98 n99)))
(declare-fun n103 () Int)
(assert (= n103 (+ n100 n101)))
(declare-fun n104 () Int)
(assert (= n104 (+ n6 n102)))
(declare-fun n105 () Int)
(assert (= n105 (+ n7 n103)))
(declare-fun n106 () Int)
(assert (= n106 (* n8 n34)))
(declare-fun n107 () Int)
(assert (= n107 (* n9 n36)))
(declare-fun n108 () Int)
(assert (= n108 (* n8 n35)))
(declare-fun n109 () Int)
(assert (= n109 (* n9 n37)))
(declare-fun n110 () Int)
(assert (= n110 (* n10 n34)))
(declare-fun n111 () Int)
(assert (= n111 (* n11 n36)))
(declare-fun n112 () Int)
(assert (= n112 (* n10 n35)))
(declare-fun n113 () Int)
(assert (= n113 (* n11 n37)))
(declare-fun n114 () Int)
(assert (= n114 (+ n106 n107)))
(declare-fun n115 () Int)
(assert (= n115 (+ n108 n109)))
(declare-fun n116 () Int)
(assert (= n116 (+ n110 n111)))
(declare-fun n117 () Int)
(assert (= n117 (+ n112 n113)))
(declare-fun n118 () Int)
(assert (= n118 (* n8 n64)))
(declare-fun n119 () Int)
(assert (= n119 (* n9 n65)))
(declare-fun n120 () Int)
(assert (= n120 (* n10 n64)))
(declare-fun n121 () Int)
(assert (= n121 (* n11 n65)))
(declare-fun n122 () Int)
(assert (= n122 (+ n118 n119)))
(declare-fun n123 () Int)
(assert (= n123 (+ n120 n121)))
(declare-fun n124 () Int)
(assert (= n124 (+ n6 n122)))
(declare-fun n125 () Int)
(assert (= n125 (+ n7 n123)))
(declare-fun n126 () Int)
(assert (= n126 (* n8 n74)))
(declare-fun n127 () Int)
(assert (= n127 (* n9 n76)))
(declare-fun n128 () Int)
(assert (= n128 (* n8 n75)))
(declare-fun n129 () Int)
(assert (= n129 (* n9 n77)))
(declare-fun n130 () Int)
(assert (= n130 (* n10 n74)))
(declare-fun n131 () Int)
(assert (= n131 (* n11 n76)))
(declare-fun n132 () Int)
(assert (= n132 (* n10 n75)))
(declare-fun n133 () Int)
(assert (= n133 (* n11 n77)))
(declare-fun n134 () Int)
(assert (= n134 (+ n126 n127)))
(declare-fun n135 () Int)
(assert (= n135 (+ n128 n129)))
(declare-fun n136 () Int)
(assert (= n136 (+ n130 n131)))
(declare-fun n137 () Int)
(assert (= n137 (+ n132 n133)))
(assert (>= n104 n124))
(assert (>= n105 n125))
(assert (>= n114 n134))
(assert (>= n115 n135))
(assert (>= n116 n136))
(assert (>= n117 n137))
(declare-fun n138 () Int)
(assert (= n138 (* n54 n12)))
(declare-fun n139 () Int)
(assert (= n139 (* n55 n13)))
(declare-fun n140 () Int)
(assert (= n140 (* n56 n12)))
(declare-fun n141 () Int)
(assert (= n141 (* n57 n13)))
(declare-fun n142 () Int)
(assert (= n142 (+ n138 n139)))
(declare-fun n143 () Int)
(assert (= n143 (+ n140 n141)))
(declare-fun n144 () Int)
(assert (= n144 (+ n44 n142)))
(declare-fun n145 () Int)
(assert (= n145 (+ n45 n143)))
(declare-fun n146 () Int)
(assert (= n146 (* n54 n14)))
(declare-fun n147 () Int)
(assert (= n147 (* n55 n16)))
(declare-fun n148 () Int)
(assert (= n148 (* n54 n15)))
(declare-fun n149 () Int)
(assert (= n149 (* n55 n17)))
(declare-fun n150 () Int)
(assert (= n150 (* n56 n14)))
(declare-fun n151 () Int)
(assert (= n151 (* n57 n16)))
(declare-fun n152 () Int)
(assert (= n152 (* n56 n15)))
(declare-fun n153 () Int)
(assert (= n153 (* n57 n17)))
(declare-fun n154 () Int)
(assert (= n154 (+ n146 n147)))
(declare-fun n155 () Int)
(assert (= n155 (+ n148 n149)))
(declare-fun n156 () Int)
(assert (= n156 (+ n150 n151)))
(declare-fun n157 () Int)
(assert (= n157 (+ n152 n153)))
(assert (>= n144 n44))
(assert (>= n145 n45))
(assert (>= n154 n54))
(assert (>= n155 n55))
(assert (>= n156 n56))
(assert (>= n157 n57))
(assert (> n81 n91))
(check-sat)
(exit)
