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
(assert (>= n2 1))
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
(assert (>= n8 1))
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
(assert (>= n14 1))
(declare-fun n18 () Int)
(assert (= n18 (* n2 n6)))
(declare-fun n19 () Int)
(assert (= n19 (* n3 n7)))
(declare-fun n20 () Int)
(assert (= n20 (* n4 n6)))
(declare-fun n21 () Int)
(assert (= n21 (* n5 n7)))
(declare-fun n22 () Int)
(assert (= n22 (+ n18 n19)))
(declare-fun n23 () Int)
(assert (= n23 (+ n20 n21)))
(declare-fun n24 () Int)
(assert (= n24 (+ n0 n22)))
(declare-fun n25 () Int)
(assert (= n25 (+ n1 n23)))
(declare-fun n26 () Int)
(assert (= n26 (* n2 n8)))
(declare-fun n27 () Int)
(assert (= n27 (* n3 n10)))
(declare-fun n28 () Int)
(assert (= n28 (* n2 n9)))
(declare-fun n29 () Int)
(assert (= n29 (* n3 n11)))
(declare-fun n30 () Int)
(assert (= n30 (* n4 n8)))
(declare-fun n31 () Int)
(assert (= n31 (* n5 n10)))
(declare-fun n32 () Int)
(assert (= n32 (* n4 n9)))
(declare-fun n33 () Int)
(assert (= n33 (* n5 n11)))
(declare-fun n34 () Int)
(assert (= n34 (+ n26 n27)))
(declare-fun n35 () Int)
(assert (= n35 (+ n28 n29)))
(declare-fun n36 () Int)
(assert (= n36 (+ n30 n31)))
(declare-fun n37 () Int)
(assert (= n37 (+ n32 n33)))
(declare-fun n38 () Int)
(assert (= n38 (* n8 n24)))
(declare-fun n39 () Int)
(assert (= n39 (* n9 n25)))
(declare-fun n40 () Int)
(assert (= n40 (* n10 n24)))
(declare-fun n41 () Int)
(assert (= n41 (* n11 n25)))
(declare-fun n42 () Int)
(assert (= n42 (+ n38 n39)))
(declare-fun n43 () Int)
(assert (= n43 (+ n40 n41)))
(declare-fun n44 () Int)
(assert (= n44 (+ n6 n42)))
(declare-fun n45 () Int)
(assert (= n45 (+ n7 n43)))
(declare-fun n46 () Int)
(assert (= n46 (* n8 n34)))
(declare-fun n47 () Int)
(assert (= n47 (* n9 n36)))
(declare-fun n48 () Int)
(assert (= n48 (* n8 n35)))
(declare-fun n49 () Int)
(assert (= n49 (* n9 n37)))
(declare-fun n50 () Int)
(assert (= n50 (* n10 n34)))
(declare-fun n51 () Int)
(assert (= n51 (* n11 n36)))
(declare-fun n52 () Int)
(assert (= n52 (* n10 n35)))
(declare-fun n53 () Int)
(assert (= n53 (* n11 n37)))
(declare-fun n54 () Int)
(assert (= n54 (+ n46 n47)))
(declare-fun n55 () Int)
(assert (= n55 (+ n48 n49)))
(declare-fun n56 () Int)
(assert (= n56 (+ n50 n51)))
(declare-fun n57 () Int)
(assert (= n57 (+ n52 n53)))
(declare-fun n58 () Int)
(assert (= n58 (* n14 n0)))
(declare-fun n59 () Int)
(assert (= n59 (* n15 n1)))
(declare-fun n60 () Int)
(assert (= n60 (* n16 n0)))
(declare-fun n61 () Int)
(assert (= n61 (* n17 n1)))
(declare-fun n62 () Int)
(assert (= n62 (+ n58 n59)))
(declare-fun n63 () Int)
(assert (= n63 (+ n60 n61)))
(declare-fun n64 () Int)
(assert (= n64 (+ n12 n62)))
(declare-fun n65 () Int)
(assert (= n65 (+ n13 n63)))
(declare-fun n66 () Int)
(assert (= n66 (* n14 n2)))
(declare-fun n67 () Int)
(assert (= n67 (* n15 n4)))
(declare-fun n68 () Int)
(assert (= n68 (* n14 n3)))
(declare-fun n69 () Int)
(assert (= n69 (* n15 n5)))
(declare-fun n70 () Int)
(assert (= n70 (* n16 n2)))
(declare-fun n71 () Int)
(assert (= n71 (* n17 n4)))
(declare-fun n72 () Int)
(assert (= n72 (* n16 n3)))
(declare-fun n73 () Int)
(assert (= n73 (* n17 n5)))
(declare-fun n74 () Int)
(assert (= n74 (+ n66 n67)))
(declare-fun n75 () Int)
(assert (= n75 (+ n68 n69)))
(declare-fun n76 () Int)
(assert (= n76 (+ n70 n71)))
(declare-fun n77 () Int)
(assert (= n77 (+ n72 n73)))
(declare-fun n78 () Int)
(assert (= n78 (* n34 n0)))
(declare-fun n79 () Int)
(assert (= n79 (* n35 n1)))
(declare-fun n80 () Int)
(assert (= n80 (* n36 n0)))
(declare-fun n81 () Int)
(assert (= n81 (* n37 n1)))
(declare-fun n82 () Int)
(assert (= n82 (+ n78 n79)))
(declare-fun n83 () Int)
(assert (= n83 (+ n80 n81)))
(declare-fun n84 () Int)
(assert (= n84 (+ n24 n82)))
(declare-fun n85 () Int)
(assert (= n85 (+ n25 n83)))
(declare-fun n86 () Int)
(assert (= n86 (* n34 n2)))
(declare-fun n87 () Int)
(assert (= n87 (* n35 n4)))
(declare-fun n88 () Int)
(assert (= n88 (* n34 n3)))
(declare-fun n89 () Int)
(assert (= n89 (* n35 n5)))
(declare-fun n90 () Int)
(assert (= n90 (* n36 n2)))
(declare-fun n91 () Int)
(assert (= n91 (* n37 n4)))
(declare-fun n92 () Int)
(assert (= n92 (* n36 n3)))
(declare-fun n93 () Int)
(assert (= n93 (* n37 n5)))
(declare-fun n94 () Int)
(assert (= n94 (+ n86 n87)))
(declare-fun n95 () Int)
(assert (= n95 (+ n88 n89)))
(declare-fun n96 () Int)
(assert (= n96 (+ n90 n91)))
(declare-fun n97 () Int)
(assert (= n97 (+ n92 n93)))
(declare-fun n98 () Int)
(assert (= n98 (* n2 n12)))
(declare-fun n99 () Int)
(assert (= n99 (* n3 n13)))
(declare-fun n100 () Int)
(assert (= n100 (* n4 n12)))
(declare-fun n101 () Int)
(assert (= n101 (* n5 n13)))
(declare-fun n102 () Int)
(assert (= n102 (+ n98 n99)))
(declare-fun n103 () Int)
(assert (= n103 (+ n100 n101)))
(declare-fun n104 () Int)
(assert (= n104 (+ n0 n102)))
(declare-fun n105 () Int)
(assert (= n105 (+ n1 n103)))
(declare-fun n106 () Int)
(assert (= n106 (* n2 n14)))
(declare-fun n107 () Int)
(assert (= n107 (* n3 n16)))
(declare-fun n108 () Int)
(assert (= n108 (* n2 n15)))
(declare-fun n109 () Int)
(assert (= n109 (* n3 n17)))
(declare-fun n110 () Int)
(assert (= n110 (* n4 n14)))
(declare-fun n111 () Int)
(assert (= n111 (* n5 n16)))
(declare-fun n112 () Int)
(assert (= n112 (* n4 n15)))
(declare-fun n113 () Int)
(assert (= n113 (* n5 n17)))
(declare-fun n114 () Int)
(assert (= n114 (+ n106 n107)))
(declare-fun n115 () Int)
(assert (= n115 (+ n108 n109)))
(declare-fun n116 () Int)
(assert (= n116 (+ n110 n111)))
(declare-fun n117 () Int)
(assert (= n117 (+ n112 n113)))
(assert (>= n104 n64))
(assert (>= n105 n65))
(assert (>= n114 n74))
(assert (>= n115 n75))
(assert (>= n116 n76))
(assert (>= n117 n77))
(declare-fun n118 () Int)
(assert (= n118 (* n54 n12)))
(declare-fun n119 () Int)
(assert (= n119 (* n55 n13)))
(declare-fun n120 () Int)
(assert (= n120 (* n56 n12)))
(declare-fun n121 () Int)
(assert (= n121 (* n57 n13)))
(declare-fun n122 () Int)
(assert (= n122 (+ n118 n119)))
(declare-fun n123 () Int)
(assert (= n123 (+ n120 n121)))
(declare-fun n124 () Int)
(assert (= n124 (+ n44 n122)))
(declare-fun n125 () Int)
(assert (= n125 (+ n45 n123)))
(declare-fun n126 () Int)
(assert (= n126 (* n54 n14)))
(declare-fun n127 () Int)
(assert (= n127 (* n55 n16)))
(declare-fun n128 () Int)
(assert (= n128 (* n54 n15)))
(declare-fun n129 () Int)
(assert (= n129 (* n55 n17)))
(declare-fun n130 () Int)
(assert (= n130 (* n56 n14)))
(declare-fun n131 () Int)
(assert (= n131 (* n57 n16)))
(declare-fun n132 () Int)
(assert (= n132 (* n56 n15)))
(declare-fun n133 () Int)
(assert (= n133 (* n57 n17)))
(declare-fun n134 () Int)
(assert (= n134 (+ n126 n127)))
(declare-fun n135 () Int)
(assert (= n135 (+ n128 n129)))
(declare-fun n136 () Int)
(assert (= n136 (+ n130 n131)))
(declare-fun n137 () Int)
(assert (= n137 (+ n132 n133)))
(declare-fun n138 () Int)
(assert (= n138 (* n34 n64)))
(declare-fun n139 () Int)
(assert (= n139 (* n35 n65)))
(declare-fun n140 () Int)
(assert (= n140 (* n36 n64)))
(declare-fun n141 () Int)
(assert (= n141 (* n37 n65)))
(declare-fun n142 () Int)
(assert (= n142 (+ n138 n139)))
(declare-fun n143 () Int)
(assert (= n143 (+ n140 n141)))
(declare-fun n144 () Int)
(assert (= n144 (+ n24 n142)))
(declare-fun n145 () Int)
(assert (= n145 (+ n25 n143)))
(declare-fun n146 () Int)
(assert (= n146 (* n34 n74)))
(declare-fun n147 () Int)
(assert (= n147 (* n35 n76)))
(declare-fun n148 () Int)
(assert (= n148 (* n34 n75)))
(declare-fun n149 () Int)
(assert (= n149 (* n35 n77)))
(declare-fun n150 () Int)
(assert (= n150 (* n36 n74)))
(declare-fun n151 () Int)
(assert (= n151 (* n37 n76)))
(declare-fun n152 () Int)
(assert (= n152 (* n36 n75)))
(declare-fun n153 () Int)
(assert (= n153 (* n37 n77)))
(declare-fun n154 () Int)
(assert (= n154 (+ n146 n147)))
(declare-fun n155 () Int)
(assert (= n155 (+ n148 n149)))
(declare-fun n156 () Int)
(assert (= n156 (+ n150 n151)))
(declare-fun n157 () Int)
(assert (= n157 (+ n152 n153)))
(assert (>= n124 n144))
(assert (>= n125 n145))
(assert (>= n134 n154))
(assert (>= n135 n155))
(assert (>= n136 n156))
(assert (>= n137 n157))
(declare-fun n158 () Int)
(assert (= n158 (* n54 n6)))
(declare-fun n159 () Int)
(assert (= n159 (* n55 n7)))
(declare-fun n160 () Int)
(assert (= n160 (* n56 n6)))
(declare-fun n161 () Int)
(assert (= n161 (* n57 n7)))
(declare-fun n162 () Int)
(assert (= n162 (+ n158 n159)))
(declare-fun n163 () Int)
(assert (= n163 (+ n160 n161)))
(declare-fun n164 () Int)
(assert (= n164 (+ n44 n162)))
(declare-fun n165 () Int)
(assert (= n165 (+ n45 n163)))
(declare-fun n166 () Int)
(assert (= n166 (* n54 n8)))
(declare-fun n167 () Int)
(assert (= n167 (* n55 n10)))
(declare-fun n168 () Int)
(assert (= n168 (* n54 n9)))
(declare-fun n169 () Int)
(assert (= n169 (* n55 n11)))
(declare-fun n170 () Int)
(assert (= n170 (* n56 n8)))
(declare-fun n171 () Int)
(assert (= n171 (* n57 n10)))
(declare-fun n172 () Int)
(assert (= n172 (* n56 n9)))
(declare-fun n173 () Int)
(assert (= n173 (* n57 n11)))
(declare-fun n174 () Int)
(assert (= n174 (+ n166 n167)))
(declare-fun n175 () Int)
(assert (= n175 (+ n168 n169)))
(declare-fun n176 () Int)
(assert (= n176 (+ n170 n171)))
(declare-fun n177 () Int)
(assert (= n177 (+ n172 n173)))
(declare-fun n178 () Int)
(assert (= n178 (* n34 n24)))
(declare-fun n179 () Int)
(assert (= n179 (* n35 n25)))
(declare-fun n180 () Int)
(assert (= n180 (* n36 n24)))
(declare-fun n181 () Int)
(assert (= n181 (* n37 n25)))
(declare-fun n182 () Int)
(assert (= n182 (+ n178 n179)))
(declare-fun n183 () Int)
(assert (= n183 (+ n180 n181)))
(declare-fun n184 () Int)
(assert (= n184 (+ n24 n182)))
(declare-fun n185 () Int)
(assert (= n185 (+ n25 n183)))
(declare-fun n186 () Int)
(assert (= n186 (* n34 n34)))
(declare-fun n187 () Int)
(assert (= n187 (* n35 n36)))
(declare-fun n188 () Int)
(assert (= n188 (* n34 n35)))
(declare-fun n189 () Int)
(assert (= n189 (* n35 n37)))
(declare-fun n190 () Int)
(assert (= n190 (* n36 n34)))
(declare-fun n191 () Int)
(assert (= n191 (* n37 n36)))
(declare-fun n192 () Int)
(assert (= n192 (* n36 n35)))
(declare-fun n193 () Int)
(assert (= n193 (* n37 n37)))
(declare-fun n194 () Int)
(assert (= n194 (+ n186 n187)))
(declare-fun n195 () Int)
(assert (= n195 (+ n188 n189)))
(declare-fun n196 () Int)
(assert (= n196 (+ n190 n191)))
(declare-fun n197 () Int)
(assert (= n197 (+ n192 n193)))
(assert (>= n164 n184))
(assert (>= n165 n185))
(assert (>= n174 n194))
(assert (>= n175 n195))
(assert (>= n176 n196))
(assert (>= n177 n197))
(declare-fun n198 () Int)
(assert (= n198 (* n94 n0)))
(declare-fun n199 () Int)
(assert (= n199 (* n95 n1)))
(declare-fun n200 () Int)
(assert (= n200 (* n96 n0)))
(declare-fun n201 () Int)
(assert (= n201 (* n97 n1)))
(declare-fun n202 () Int)
(assert (= n202 (+ n198 n199)))
(declare-fun n203 () Int)
(assert (= n203 (+ n200 n201)))
(declare-fun n204 () Int)
(assert (= n204 (+ n84 n202)))
(declare-fun n205 () Int)
(assert (= n205 (+ n85 n203)))
(declare-fun n206 () Int)
(assert (= n206 (* n94 n2)))
(declare-fun n207 () Int)
(assert (= n207 (* n95 n4)))
(declare-fun n208 () Int)
(assert (= n208 (* n94 n3)))
(declare-fun n209 () Int)
(assert (= n209 (* n95 n5)))
(declare-fun n210 () Int)
(assert (= n210 (* n96 n2)))
(declare-fun n211 () Int)
(assert (= n211 (* n97 n4)))
(declare-fun n212 () Int)
(assert (= n212 (* n96 n3)))
(declare-fun n213 () Int)
(assert (= n213 (* n97 n5)))
(declare-fun n214 () Int)
(assert (= n214 (+ n206 n207)))
(declare-fun n215 () Int)
(assert (= n215 (+ n208 n209)))
(declare-fun n216 () Int)
(assert (= n216 (+ n210 n211)))
(declare-fun n217 () Int)
(assert (= n217 (+ n212 n213)))
(declare-fun n218 () Int)
(assert (= n218 (* n54 n0)))
(declare-fun n219 () Int)
(assert (= n219 (* n55 n1)))
(declare-fun n220 () Int)
(assert (= n220 (* n56 n0)))
(declare-fun n221 () Int)
(assert (= n221 (* n57 n1)))
(declare-fun n222 () Int)
(assert (= n222 (+ n218 n219)))
(declare-fun n223 () Int)
(assert (= n223 (+ n220 n221)))
(declare-fun n224 () Int)
(assert (= n224 (+ n44 n222)))
(declare-fun n225 () Int)
(assert (= n225 (+ n45 n223)))
(declare-fun n226 () Int)
(assert (= n226 (* n54 n2)))
(declare-fun n227 () Int)
(assert (= n227 (* n55 n4)))
(declare-fun n228 () Int)
(assert (= n228 (* n54 n3)))
(declare-fun n229 () Int)
(assert (= n229 (* n55 n5)))
(declare-fun n230 () Int)
(assert (= n230 (* n56 n2)))
(declare-fun n231 () Int)
(assert (= n231 (* n57 n4)))
(declare-fun n232 () Int)
(assert (= n232 (* n56 n3)))
(declare-fun n233 () Int)
(assert (= n233 (* n57 n5)))
(declare-fun n234 () Int)
(assert (= n234 (+ n226 n227)))
(declare-fun n235 () Int)
(assert (= n235 (+ n228 n229)))
(declare-fun n236 () Int)
(assert (= n236 (+ n230 n231)))
(declare-fun n237 () Int)
(assert (= n237 (+ n232 n233)))
(assert (>= n204 n224))
(assert (>= n205 n225))
(assert (>= n214 n234))
(assert (>= n215 n235))
(assert (>= n216 n236))
(assert (>= n217 n237))
(assert (or (> n104 n64) (> n124 n144) (> n164 n184) (> n204 n224)))
(check-sat)
(exit)