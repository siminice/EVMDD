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
(assert (= n18 (* n8 n6)))
(declare-fun n19 () Int)
(assert (= n19 (* n9 n7)))
(declare-fun n20 () Int)
(assert (= n20 (* n10 n6)))
(declare-fun n21 () Int)
(assert (= n21 (* n11 n7)))
(declare-fun n22 () Int)
(assert (= n22 (+ n18 n19)))
(declare-fun n23 () Int)
(assert (= n23 (+ n20 n21)))
(declare-fun n24 () Int)
(assert (= n24 (+ n6 n22)))
(declare-fun n25 () Int)
(assert (= n25 (+ n7 n23)))
(declare-fun n26 () Int)
(assert (= n26 (* n8 n8)))
(declare-fun n27 () Int)
(assert (= n27 (* n9 n10)))
(declare-fun n28 () Int)
(assert (= n28 (* n8 n9)))
(declare-fun n29 () Int)
(assert (= n29 (* n9 n11)))
(declare-fun n30 () Int)
(assert (= n30 (* n10 n8)))
(declare-fun n31 () Int)
(assert (= n31 (* n11 n10)))
(declare-fun n32 () Int)
(assert (= n32 (* n10 n9)))
(declare-fun n33 () Int)
(assert (= n33 (* n11 n11)))
(declare-fun n34 () Int)
(assert (= n34 (+ n26 n27)))
(declare-fun n35 () Int)
(assert (= n35 (+ n28 n29)))
(declare-fun n36 () Int)
(assert (= n36 (+ n30 n31)))
(declare-fun n37 () Int)
(assert (= n37 (+ n32 n33)))
(declare-fun n38 () Int)
(assert (= n38 (* n14 n24)))
(declare-fun n39 () Int)
(assert (= n39 (* n15 n25)))
(declare-fun n40 () Int)
(assert (= n40 (* n16 n24)))
(declare-fun n41 () Int)
(assert (= n41 (* n17 n25)))
(declare-fun n42 () Int)
(assert (= n42 (+ n38 n39)))
(declare-fun n43 () Int)
(assert (= n43 (+ n40 n41)))
(declare-fun n44 () Int)
(assert (= n44 (+ n12 n42)))
(declare-fun n45 () Int)
(assert (= n45 (+ n13 n43)))
(declare-fun n46 () Int)
(assert (= n46 (* n14 n34)))
(declare-fun n47 () Int)
(assert (= n47 (* n15 n36)))
(declare-fun n48 () Int)
(assert (= n48 (* n14 n35)))
(declare-fun n49 () Int)
(assert (= n49 (* n15 n37)))
(declare-fun n50 () Int)
(assert (= n50 (* n16 n34)))
(declare-fun n51 () Int)
(assert (= n51 (* n17 n36)))
(declare-fun n52 () Int)
(assert (= n52 (* n16 n35)))
(declare-fun n53 () Int)
(assert (= n53 (* n17 n37)))
(declare-fun n54 () Int)
(assert (= n54 (+ n46 n47)))
(declare-fun n55 () Int)
(assert (= n55 (+ n48 n49)))
(declare-fun n56 () Int)
(assert (= n56 (+ n50 n51)))
(declare-fun n57 () Int)
(assert (= n57 (+ n52 n53)))
(declare-fun n58 () Int)
(assert (= n58 (* n14 n12)))
(declare-fun n59 () Int)
(assert (= n59 (* n15 n13)))
(declare-fun n60 () Int)
(assert (= n60 (* n16 n12)))
(declare-fun n61 () Int)
(assert (= n61 (* n17 n13)))
(declare-fun n62 () Int)
(assert (= n62 (+ n58 n59)))
(declare-fun n63 () Int)
(assert (= n63 (+ n60 n61)))
(declare-fun n64 () Int)
(assert (= n64 (+ n12 n62)))
(declare-fun n65 () Int)
(assert (= n65 (+ n13 n63)))
(declare-fun n66 () Int)
(assert (= n66 (* n14 n14)))
(declare-fun n67 () Int)
(assert (= n67 (* n15 n16)))
(declare-fun n68 () Int)
(assert (= n68 (* n14 n15)))
(declare-fun n69 () Int)
(assert (= n69 (* n15 n17)))
(declare-fun n70 () Int)
(assert (= n70 (* n16 n14)))
(declare-fun n71 () Int)
(assert (= n71 (* n17 n16)))
(declare-fun n72 () Int)
(assert (= n72 (* n16 n15)))
(declare-fun n73 () Int)
(assert (= n73 (* n17 n17)))
(declare-fun n74 () Int)
(assert (= n74 (+ n66 n67)))
(declare-fun n75 () Int)
(assert (= n75 (+ n68 n69)))
(declare-fun n76 () Int)
(assert (= n76 (+ n70 n71)))
(declare-fun n77 () Int)
(assert (= n77 (+ n72 n73)))
(declare-fun n78 () Int)
(assert (= n78 (* n54 n12)))
(declare-fun n79 () Int)
(assert (= n79 (* n55 n13)))
(declare-fun n80 () Int)
(assert (= n80 (* n56 n12)))
(declare-fun n81 () Int)
(assert (= n81 (* n57 n13)))
(declare-fun n82 () Int)
(assert (= n82 (+ n78 n79)))
(declare-fun n83 () Int)
(assert (= n83 (+ n80 n81)))
(declare-fun n84 () Int)
(assert (= n84 (+ n44 n82)))
(declare-fun n85 () Int)
(assert (= n85 (+ n45 n83)))
(declare-fun n86 () Int)
(assert (= n86 (* n54 n14)))
(declare-fun n87 () Int)
(assert (= n87 (* n55 n16)))
(declare-fun n88 () Int)
(assert (= n88 (* n54 n15)))
(declare-fun n89 () Int)
(assert (= n89 (* n55 n17)))
(declare-fun n90 () Int)
(assert (= n90 (* n56 n14)))
(declare-fun n91 () Int)
(assert (= n91 (* n57 n16)))
(declare-fun n92 () Int)
(assert (= n92 (* n56 n15)))
(declare-fun n93 () Int)
(assert (= n93 (* n57 n17)))
(declare-fun n94 () Int)
(assert (= n94 (+ n86 n87)))
(declare-fun n95 () Int)
(assert (= n95 (+ n88 n89)))
(declare-fun n96 () Int)
(assert (= n96 (+ n90 n91)))
(declare-fun n97 () Int)
(assert (= n97 (+ n92 n93)))
(declare-fun n98 () Int)
(assert (= n98 (* n8 n84)))
(declare-fun n99 () Int)
(assert (= n99 (* n9 n85)))
(declare-fun n100 () Int)
(assert (= n100 (* n10 n84)))
(declare-fun n101 () Int)
(assert (= n101 (* n11 n85)))
(declare-fun n102 () Int)
(assert (= n102 (+ n98 n99)))
(declare-fun n103 () Int)
(assert (= n103 (+ n100 n101)))
(declare-fun n104 () Int)
(assert (= n104 (+ n6 n102)))
(declare-fun n105 () Int)
(assert (= n105 (+ n7 n103)))
(declare-fun n106 () Int)
(assert (= n106 (* n8 n94)))
(declare-fun n107 () Int)
(assert (= n107 (* n9 n96)))
(declare-fun n108 () Int)
(assert (= n108 (* n8 n95)))
(declare-fun n109 () Int)
(assert (= n109 (* n9 n97)))
(declare-fun n110 () Int)
(assert (= n110 (* n10 n94)))
(declare-fun n111 () Int)
(assert (= n111 (* n11 n96)))
(declare-fun n112 () Int)
(assert (= n112 (* n10 n95)))
(declare-fun n113 () Int)
(assert (= n113 (* n11 n97)))
(declare-fun n114 () Int)
(assert (= n114 (+ n106 n107)))
(declare-fun n115 () Int)
(assert (= n115 (+ n108 n109)))
(declare-fun n116 () Int)
(assert (= n116 (+ n110 n111)))
(declare-fun n117 () Int)
(assert (= n117 (+ n112 n113)))
(declare-fun n118 () Int)
(assert (= n118 (* n4 n24)))
(declare-fun n119 () Int)
(assert (= n119 (* n5 n25)))
(declare-fun n120 () Int)
(assert (= n120 (+ n118 n119)))
(declare-fun n121 () Int)
(assert (= n121 (+ n3 n120)))
(declare-fun n122 () Int)
(assert (= n122 (* n4 n34)))
(declare-fun n123 () Int)
(assert (= n123 (* n5 n36)))
(declare-fun n124 () Int)
(assert (= n124 (* n4 n35)))
(declare-fun n125 () Int)
(assert (= n125 (* n5 n37)))
(declare-fun n126 () Int)
(assert (= n126 (+ n122 n123)))
(declare-fun n127 () Int)
(assert (= n127 (+ n124 n125)))
(declare-fun n128 () Int)
(assert (= n128 (* n8 n64)))
(declare-fun n129 () Int)
(assert (= n129 (* n9 n65)))
(declare-fun n130 () Int)
(assert (= n130 (* n10 n64)))
(declare-fun n131 () Int)
(assert (= n131 (* n11 n65)))
(declare-fun n132 () Int)
(assert (= n132 (+ n128 n129)))
(declare-fun n133 () Int)
(assert (= n133 (+ n130 n131)))
(declare-fun n134 () Int)
(assert (= n134 (+ n6 n132)))
(declare-fun n135 () Int)
(assert (= n135 (+ n7 n133)))
(declare-fun n136 () Int)
(assert (= n136 (* n8 n74)))
(declare-fun n137 () Int)
(assert (= n137 (* n9 n76)))
(declare-fun n138 () Int)
(assert (= n138 (* n8 n75)))
(declare-fun n139 () Int)
(assert (= n139 (* n9 n77)))
(declare-fun n140 () Int)
(assert (= n140 (* n10 n74)))
(declare-fun n141 () Int)
(assert (= n141 (* n11 n76)))
(declare-fun n142 () Int)
(assert (= n142 (* n10 n75)))
(declare-fun n143 () Int)
(assert (= n143 (* n11 n77)))
(declare-fun n144 () Int)
(assert (= n144 (+ n136 n137)))
(declare-fun n145 () Int)
(assert (= n145 (+ n138 n139)))
(declare-fun n146 () Int)
(assert (= n146 (+ n140 n141)))
(declare-fun n147 () Int)
(assert (= n147 (+ n142 n143)))
(declare-fun n148 () Int)
(assert (= n148 (* n4 n12)))
(declare-fun n149 () Int)
(assert (= n149 (* n5 n13)))
(declare-fun n150 () Int)
(assert (= n150 (+ n148 n149)))
(declare-fun n151 () Int)
(assert (= n151 (+ n3 n150)))
(declare-fun n152 () Int)
(assert (= n152 (* n4 n14)))
(declare-fun n153 () Int)
(assert (= n153 (* n5 n16)))
(declare-fun n154 () Int)
(assert (= n154 (* n4 n15)))
(declare-fun n155 () Int)
(assert (= n155 (* n5 n17)))
(declare-fun n156 () Int)
(assert (= n156 (+ n152 n153)))
(declare-fun n157 () Int)
(assert (= n157 (+ n154 n155)))
(declare-fun n158 () Int)
(assert (= n158 (* n8 n12)))
(declare-fun n159 () Int)
(assert (= n159 (* n9 n13)))
(declare-fun n160 () Int)
(assert (= n160 (* n10 n12)))
(declare-fun n161 () Int)
(assert (= n161 (* n11 n13)))
(declare-fun n162 () Int)
(assert (= n162 (+ n158 n159)))
(declare-fun n163 () Int)
(assert (= n163 (+ n160 n161)))
(declare-fun n164 () Int)
(assert (= n164 (+ n6 n162)))
(declare-fun n165 () Int)
(assert (= n165 (+ n7 n163)))
(declare-fun n166 () Int)
(assert (= n166 (* n8 n14)))
(declare-fun n167 () Int)
(assert (= n167 (* n9 n16)))
(declare-fun n168 () Int)
(assert (= n168 (* n8 n15)))
(declare-fun n169 () Int)
(assert (= n169 (* n9 n17)))
(declare-fun n170 () Int)
(assert (= n170 (* n10 n14)))
(declare-fun n171 () Int)
(assert (= n171 (* n11 n16)))
(declare-fun n172 () Int)
(assert (= n172 (* n10 n15)))
(declare-fun n173 () Int)
(assert (= n173 (* n11 n17)))
(declare-fun n174 () Int)
(assert (= n174 (+ n166 n167)))
(declare-fun n175 () Int)
(assert (= n175 (+ n168 n169)))
(declare-fun n176 () Int)
(assert (= n176 (+ n170 n171)))
(declare-fun n177 () Int)
(assert (= n177 (+ n172 n173)))
(declare-fun n178 () Int)
(assert (= n178 (* n126 n104)))
(declare-fun n179 () Int)
(assert (= n179 (* n127 n105)))
(declare-fun n180 () Int)
(assert (= n180 (+ n178 n179)))
(declare-fun n181 () Int)
(assert (= n181 (+ n121 n180)))
(declare-fun n182 () Int)
(assert (= n182 (* n126 n114)))
(declare-fun n183 () Int)
(assert (= n183 (* n127 n116)))
(declare-fun n184 () Int)
(assert (= n184 (* n126 n115)))
(declare-fun n185 () Int)
(assert (= n185 (* n127 n117)))
(declare-fun n186 () Int)
(assert (= n186 (+ n182 n183)))
(declare-fun n187 () Int)
(assert (= n187 (+ n184 n185)))
(declare-fun n188 () Int)
(assert (= n188 (* n156 n164)))
(declare-fun n189 () Int)
(assert (= n189 (* n157 n165)))
(declare-fun n190 () Int)
(assert (= n190 (+ n188 n189)))
(declare-fun n191 () Int)
(assert (= n191 (+ n151 n190)))
(declare-fun n192 () Int)
(assert (= n192 (* n156 n174)))
(declare-fun n193 () Int)
(assert (= n193 (* n157 n176)))
(declare-fun n194 () Int)
(assert (= n194 (* n156 n175)))
(declare-fun n195 () Int)
(assert (= n195 (* n157 n177)))
(declare-fun n196 () Int)
(assert (= n196 (+ n192 n193)))
(declare-fun n197 () Int)
(assert (= n197 (+ n194 n195)))
(declare-fun n198 () Int)
(assert (= n198 (* n4 n104)))
(declare-fun n199 () Int)
(assert (= n199 (* n5 n105)))
(declare-fun n200 () Int)
(assert (= n200 (+ n198 n199)))
(declare-fun n201 () Int)
(assert (= n201 (+ n3 n200)))
(declare-fun n202 () Int)
(assert (= n202 (* n4 n114)))
(declare-fun n203 () Int)
(assert (= n203 (* n5 n116)))
(declare-fun n204 () Int)
(assert (= n204 (* n4 n115)))
(declare-fun n205 () Int)
(assert (= n205 (* n5 n117)))
(declare-fun n206 () Int)
(assert (= n206 (+ n202 n203)))
(declare-fun n207 () Int)
(assert (= n207 (+ n204 n205)))
(assert (>= n151 n201))
(assert (>= n156 n206))
(assert (>= n157 n207))
(declare-fun n208 () Int)
(assert (= n208 (* n126 n12)))
(declare-fun n209 () Int)
(assert (= n209 (* n127 n13)))
(declare-fun n210 () Int)
(assert (= n210 (+ n208 n209)))
(declare-fun n211 () Int)
(assert (= n211 (+ n121 n210)))
(declare-fun n212 () Int)
(assert (= n212 (* n126 n14)))
(declare-fun n213 () Int)
(assert (= n213 (* n127 n16)))
(declare-fun n214 () Int)
(assert (= n214 (* n126 n15)))
(declare-fun n215 () Int)
(assert (= n215 (* n127 n17)))
(declare-fun n216 () Int)
(assert (= n216 (+ n212 n213)))
(declare-fun n217 () Int)
(assert (= n217 (+ n214 n215)))
(assert (>= n151 n211))
(assert (>= n156 n216))
(assert (>= n157 n217))
(declare-fun n218 () Int)
(assert (= n218 (* n4 n134)))
(declare-fun n219 () Int)
(assert (= n219 (* n5 n135)))
(declare-fun n220 () Int)
(assert (= n220 (+ n218 n219)))
(declare-fun n221 () Int)
(assert (= n221 (+ n3 n220)))
(declare-fun n222 () Int)
(assert (= n222 (* n4 n144)))
(declare-fun n223 () Int)
(assert (= n223 (* n5 n146)))
(declare-fun n224 () Int)
(assert (= n224 (* n4 n145)))
(declare-fun n225 () Int)
(assert (= n225 (* n5 n147)))
(declare-fun n226 () Int)
(assert (= n226 (+ n222 n223)))
(declare-fun n227 () Int)
(assert (= n227 (+ n224 n225)))
(assert (>= n191 n221))
(assert (>= n196 n226))
(assert (>= n197 n227))
(assert (>= n191 n151))
(assert (>= n196 n156))
(assert (>= n197 n157))
(declare-fun n228 () Int)
(assert (= n228 (* n126 n134)))
(declare-fun n229 () Int)
(assert (= n229 (* n127 n135)))
(declare-fun n230 () Int)
(assert (= n230 (+ n228 n229)))
(declare-fun n231 () Int)
(assert (= n231 (+ n121 n230)))
(declare-fun n232 () Int)
(assert (= n232 (* n126 n144)))
(declare-fun n233 () Int)
(assert (= n233 (* n127 n146)))
(declare-fun n234 () Int)
(assert (= n234 (* n126 n145)))
(declare-fun n235 () Int)
(assert (= n235 (* n127 n147)))
(declare-fun n236 () Int)
(assert (= n236 (+ n232 n233)))
(declare-fun n237 () Int)
(assert (= n237 (+ n234 n235)))
(assert (>= n181 n231))
(assert (>= n186 n236))
(assert (>= n187 n237))
(assert (>= n181 n151))
(assert (>= n186 n156))
(assert (>= n187 n157))
(declare-fun n238 () Int)
(assert (= n238 (* n4 n84)))
(declare-fun n239 () Int)
(assert (= n239 (* n5 n85)))
(declare-fun n240 () Int)
(assert (= n240 (+ n238 n239)))
(declare-fun n241 () Int)
(assert (= n241 (+ n3 n240)))
(declare-fun n242 () Int)
(assert (= n242 (* n4 n94)))
(declare-fun n243 () Int)
(assert (= n243 (* n5 n96)))
(declare-fun n244 () Int)
(assert (= n244 (* n4 n95)))
(declare-fun n245 () Int)
(assert (= n245 (* n5 n97)))
(declare-fun n246 () Int)
(assert (= n246 (+ n242 n243)))
(declare-fun n247 () Int)
(assert (= n247 (+ n244 n245)))
(declare-fun n248 () Int)
(assert (= n248 (* n126 n64)))
(declare-fun n249 () Int)
(assert (= n249 (* n127 n65)))
(declare-fun n250 () Int)
(assert (= n250 (+ n248 n249)))
(declare-fun n251 () Int)
(assert (= n251 (+ n121 n250)))
(declare-fun n252 () Int)
(assert (= n252 (* n126 n74)))
(declare-fun n253 () Int)
(assert (= n253 (* n127 n76)))
(declare-fun n254 () Int)
(assert (= n254 (* n126 n75)))
(declare-fun n255 () Int)
(assert (= n255 (* n127 n77)))
(declare-fun n256 () Int)
(assert (= n256 (+ n252 n253)))
(declare-fun n257 () Int)
(assert (= n257 (+ n254 n255)))
(assert (>= n241 n251))
(assert (>= n246 n256))
(assert (>= n247 n257))
(declare-fun n258 () Int)
(assert (= n258 (* n14 n104)))
(declare-fun n259 () Int)
(assert (= n259 (* n15 n105)))
(declare-fun n260 () Int)
(assert (= n260 (* n16 n104)))
(declare-fun n261 () Int)
(assert (= n261 (* n17 n105)))
(declare-fun n262 () Int)
(assert (= n262 (+ n258 n259)))
(declare-fun n263 () Int)
(assert (= n263 (+ n260 n261)))
(declare-fun n264 () Int)
(assert (= n264 (+ n12 n262)))
(declare-fun n265 () Int)
(assert (= n265 (+ n13 n263)))
(declare-fun n266 () Int)
(assert (= n266 (* n14 n114)))
(declare-fun n267 () Int)
(assert (= n267 (* n15 n116)))
(declare-fun n268 () Int)
(assert (= n268 (* n14 n115)))
(declare-fun n269 () Int)
(assert (= n269 (* n15 n117)))
(declare-fun n270 () Int)
(assert (= n270 (* n16 n114)))
(declare-fun n271 () Int)
(assert (= n271 (* n17 n116)))
(declare-fun n272 () Int)
(assert (= n272 (* n16 n115)))
(declare-fun n273 () Int)
(assert (= n273 (* n17 n117)))
(declare-fun n274 () Int)
(assert (= n274 (+ n266 n267)))
(declare-fun n275 () Int)
(assert (= n275 (+ n268 n269)))
(declare-fun n276 () Int)
(assert (= n276 (+ n270 n271)))
(declare-fun n277 () Int)
(assert (= n277 (+ n272 n273)))
(assert (>= n64 n264))
(assert (>= n65 n265))
(assert (>= n74 n274))
(assert (>= n75 n275))
(assert (>= n76 n276))
(assert (>= n77 n277))
(declare-fun n278 () Int)
(assert (= n278 (* n74 n164)))
(declare-fun n279 () Int)
(assert (= n279 (* n75 n165)))
(declare-fun n280 () Int)
(assert (= n280 (* n76 n164)))
(declare-fun n281 () Int)
(assert (= n281 (* n77 n165)))
(declare-fun n282 () Int)
(assert (= n282 (+ n278 n279)))
(declare-fun n283 () Int)
(assert (= n283 (+ n280 n281)))
(declare-fun n284 () Int)
(assert (= n284 (+ n64 n282)))
(declare-fun n285 () Int)
(assert (= n285 (+ n65 n283)))
(declare-fun n286 () Int)
(assert (= n286 (* n74 n174)))
(declare-fun n287 () Int)
(assert (= n287 (* n75 n176)))
(declare-fun n288 () Int)
(assert (= n288 (* n74 n175)))
(declare-fun n289 () Int)
(assert (= n289 (* n75 n177)))
(declare-fun n290 () Int)
(assert (= n290 (* n76 n174)))
(declare-fun n291 () Int)
(assert (= n291 (* n77 n176)))
(declare-fun n292 () Int)
(assert (= n292 (* n76 n175)))
(declare-fun n293 () Int)
(assert (= n293 (* n77 n177)))
(declare-fun n294 () Int)
(assert (= n294 (+ n286 n287)))
(declare-fun n295 () Int)
(assert (= n295 (+ n288 n289)))
(declare-fun n296 () Int)
(assert (= n296 (+ n290 n291)))
(declare-fun n297 () Int)
(assert (= n297 (+ n292 n293)))
(declare-fun n298 () Int)
(assert (= n298 (* n14 n134)))
(declare-fun n299 () Int)
(assert (= n299 (* n15 n135)))
(declare-fun n300 () Int)
(assert (= n300 (* n16 n134)))
(declare-fun n301 () Int)
(assert (= n301 (* n17 n135)))
(declare-fun n302 () Int)
(assert (= n302 (+ n298 n299)))
(declare-fun n303 () Int)
(assert (= n303 (+ n300 n301)))
(declare-fun n304 () Int)
(assert (= n304 (+ n12 n302)))
(declare-fun n305 () Int)
(assert (= n305 (+ n13 n303)))
(declare-fun n306 () Int)
(assert (= n306 (* n14 n144)))
(declare-fun n307 () Int)
(assert (= n307 (* n15 n146)))
(declare-fun n308 () Int)
(assert (= n308 (* n14 n145)))
(declare-fun n309 () Int)
(assert (= n309 (* n15 n147)))
(declare-fun n310 () Int)
(assert (= n310 (* n16 n144)))
(declare-fun n311 () Int)
(assert (= n311 (* n17 n146)))
(declare-fun n312 () Int)
(assert (= n312 (* n16 n145)))
(declare-fun n313 () Int)
(assert (= n313 (* n17 n147)))
(declare-fun n314 () Int)
(assert (= n314 (+ n306 n307)))
(declare-fun n315 () Int)
(assert (= n315 (+ n308 n309)))
(declare-fun n316 () Int)
(assert (= n316 (+ n310 n311)))
(declare-fun n317 () Int)
(assert (= n317 (+ n312 n313)))
(assert (>= n284 n304))
(assert (>= n285 n305))
(assert (>= n294 n314))
(assert (>= n295 n315))
(assert (>= n296 n316))
(assert (>= n297 n317))
(declare-fun n318 () Int)
(assert (= n318 (* n54 n104)))
(declare-fun n319 () Int)
(assert (= n319 (* n55 n105)))
(declare-fun n320 () Int)
(assert (= n320 (* n56 n104)))
(declare-fun n321 () Int)
(assert (= n321 (* n57 n105)))
(declare-fun n322 () Int)
(assert (= n322 (+ n318 n319)))
(declare-fun n323 () Int)
(assert (= n323 (+ n320 n321)))
(declare-fun n324 () Int)
(assert (= n324 (+ n44 n322)))
(declare-fun n325 () Int)
(assert (= n325 (+ n45 n323)))
(declare-fun n326 () Int)
(assert (= n326 (* n54 n114)))
(declare-fun n327 () Int)
(assert (= n327 (* n55 n116)))
(declare-fun n328 () Int)
(assert (= n328 (* n54 n115)))
(declare-fun n329 () Int)
(assert (= n329 (* n55 n117)))
(declare-fun n330 () Int)
(assert (= n330 (* n56 n114)))
(declare-fun n331 () Int)
(assert (= n331 (* n57 n116)))
(declare-fun n332 () Int)
(assert (= n332 (* n56 n115)))
(declare-fun n333 () Int)
(assert (= n333 (* n57 n117)))
(declare-fun n334 () Int)
(assert (= n334 (+ n326 n327)))
(declare-fun n335 () Int)
(assert (= n335 (+ n328 n329)))
(declare-fun n336 () Int)
(assert (= n336 (+ n330 n331)))
(declare-fun n337 () Int)
(assert (= n337 (+ n332 n333)))
(declare-fun n338 () Int)
(assert (= n338 (* n54 n134)))
(declare-fun n339 () Int)
(assert (= n339 (* n55 n135)))
(declare-fun n340 () Int)
(assert (= n340 (* n56 n134)))
(declare-fun n341 () Int)
(assert (= n341 (* n57 n135)))
(declare-fun n342 () Int)
(assert (= n342 (+ n338 n339)))
(declare-fun n343 () Int)
(assert (= n343 (+ n340 n341)))
(declare-fun n344 () Int)
(assert (= n344 (+ n44 n342)))
(declare-fun n345 () Int)
(assert (= n345 (+ n45 n343)))
(declare-fun n346 () Int)
(assert (= n346 (* n54 n144)))
(declare-fun n347 () Int)
(assert (= n347 (* n55 n146)))
(declare-fun n348 () Int)
(assert (= n348 (* n54 n145)))
(declare-fun n349 () Int)
(assert (= n349 (* n55 n147)))
(declare-fun n350 () Int)
(assert (= n350 (* n56 n144)))
(declare-fun n351 () Int)
(assert (= n351 (* n57 n146)))
(declare-fun n352 () Int)
(assert (= n352 (* n56 n145)))
(declare-fun n353 () Int)
(assert (= n353 (* n57 n147)))
(declare-fun n354 () Int)
(assert (= n354 (+ n346 n347)))
(declare-fun n355 () Int)
(assert (= n355 (+ n348 n349)))
(declare-fun n356 () Int)
(assert (= n356 (+ n350 n351)))
(declare-fun n357 () Int)
(assert (= n357 (+ n352 n353)))
(assert (>= n324 n344))
(assert (>= n325 n345))
(assert (>= n334 n354))
(assert (>= n335 n355))
(assert (>= n336 n356))
(assert (>= n337 n357))
(declare-fun n358 () Int)
(assert (= n358 (* n14 n84)))
(declare-fun n359 () Int)
(assert (= n359 (* n15 n85)))
(declare-fun n360 () Int)
(assert (= n360 (* n16 n84)))
(declare-fun n361 () Int)
(assert (= n361 (* n17 n85)))
(declare-fun n362 () Int)
(assert (= n362 (+ n358 n359)))
(declare-fun n363 () Int)
(assert (= n363 (+ n360 n361)))
(declare-fun n364 () Int)
(assert (= n364 (+ n12 n362)))
(declare-fun n365 () Int)
(assert (= n365 (+ n13 n363)))
(declare-fun n366 () Int)
(assert (= n366 (* n14 n94)))
(declare-fun n367 () Int)
(assert (= n367 (* n15 n96)))
(declare-fun n368 () Int)
(assert (= n368 (* n14 n95)))
(declare-fun n369 () Int)
(assert (= n369 (* n15 n97)))
(declare-fun n370 () Int)
(assert (= n370 (* n16 n94)))
(declare-fun n371 () Int)
(assert (= n371 (* n17 n96)))
(declare-fun n372 () Int)
(assert (= n372 (* n16 n95)))
(declare-fun n373 () Int)
(assert (= n373 (* n17 n97)))
(declare-fun n374 () Int)
(assert (= n374 (+ n366 n367)))
(declare-fun n375 () Int)
(assert (= n375 (+ n368 n369)))
(declare-fun n376 () Int)
(assert (= n376 (+ n370 n371)))
(declare-fun n377 () Int)
(assert (= n377 (+ n372 n373)))
(declare-fun n378 () Int)
(assert (= n378 (* n54 n64)))
(declare-fun n379 () Int)
(assert (= n379 (* n55 n65)))
(declare-fun n380 () Int)
(assert (= n380 (* n56 n64)))
(declare-fun n381 () Int)
(assert (= n381 (* n57 n65)))
(declare-fun n382 () Int)
(assert (= n382 (+ n378 n379)))
(declare-fun n383 () Int)
(assert (= n383 (+ n380 n381)))
(declare-fun n384 () Int)
(assert (= n384 (+ n44 n382)))
(declare-fun n385 () Int)
(assert (= n385 (+ n45 n383)))
(declare-fun n386 () Int)
(assert (= n386 (* n54 n74)))
(declare-fun n387 () Int)
(assert (= n387 (* n55 n76)))
(declare-fun n388 () Int)
(assert (= n388 (* n54 n75)))
(declare-fun n389 () Int)
(assert (= n389 (* n55 n77)))
(declare-fun n390 () Int)
(assert (= n390 (* n56 n74)))
(declare-fun n391 () Int)
(assert (= n391 (* n57 n76)))
(declare-fun n392 () Int)
(assert (= n392 (* n56 n75)))
(declare-fun n393 () Int)
(assert (= n393 (* n57 n77)))
(declare-fun n394 () Int)
(assert (= n394 (+ n386 n387)))
(declare-fun n395 () Int)
(assert (= n395 (+ n388 n389)))
(declare-fun n396 () Int)
(assert (= n396 (+ n390 n391)))
(declare-fun n397 () Int)
(assert (= n397 (+ n392 n393)))
(assert (>= n364 n384))
(assert (>= n365 n385))
(assert (>= n374 n394))
(assert (>= n375 n395))
(assert (>= n376 n396))
(assert (>= n377 n397))
(assert (or (> n151 n201) (> n151 n211) (> n191 n221) (> n191 n151) (> n181 n231) (> n181 n151) (> n241 n251)))
(check-sat)
(exit)
