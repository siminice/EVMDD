/** \file
 * \author Pierre Roux
 * \date 2009
 *
 * \brief General include header.
 *
 * Include this file evmdd/evmdd.h to include all evmdd library at once.
 */

#include "mdd_manager.h"
#include "mdd_node.h"
#include "mdd_ops.h"
#include "evmdd_node.h"
#include "evmdd_ops.h"
#include "events.h"
#include "saturate.h"
#include "saturate_dist.h"
#include "saturate_dist2.h"
#include "saturate_bounded.h"
#include "bigint.h"

/** \example example.c */

/** \example bfs.c */

/** \example ctl.c */

/** \mainpage
 *
 * \section intro_sec Introduction
 *
 * EVMDD is a library implementing Edge Valued Multiway Decision Diagrams
 * and Multiway Decision Diagrams for representing boolean and arithmetic
 * finite sets and functions for the purpose of symbolic model checking.
 * Also implemented is a so called saturation algorithm which proved
 * to be often far more efficient than classical breadth first search
 * for the often expensive operation of state space construction.
 *
 * On some examples, usage of this library appears to be
 * a few order of magnitudes faster than the broadly used CUDD
 * (http://vlsi.colorado.edu/~fabio/CUDD/).
 *
 * Please note that this material is in early development stage
 * so some bugs may subsist or some feature are certainly missing.
 * In this case, please report it to the authors,
 * every bug reports and suggestions are welcomed.
 *
 * \section example_sec Examples
 *
 * \dontinclude example.c
 *
 * First a simple state space construction example.
 *
 * Before being able to do anything, we have to
 * instantiate a manager:
 * \skip ranging
 * \until set_var_names
 *
 * Then we can build an initial state:
 * \until mdd_ref
 * Notice that just after each function returning a diagram
 * we call either the function evmdd_ref or the function mdd_ref.
 * That's because we have to make the manager aware that we are using
 * this diagrams. When we will no longer use them, we will have to call
 * respectively evmdd_unref or mdd_unref to allow garbage collection to
 * release memory if nobody else use it.
 * \until mdd_ref
 *
 * Then we can build a little transition relation:
 * \until evmdd_unref(manager, xpMxP2)
 * For this transition relation to be used in state space construction, we have to register it:
 * \until mdd_unref
 * As the documentation of function event_register show, it allows to add identities at given levels
 * which can be very useful for locally synchronous globally asynchronous systems.
 * Furthemore this is easy to do and efficient since internal representation compress
 * very well identity patterns (x' = x) even if we don't need it here since we have only one variable.
 * The global transition relation is the logic disjunction of all registered events.
 *
 * We can finally compute state space:
 * \until mdd_unref
 * Here our example is ridiculously small but saturation algorithm can be far more efficient than
 * classical symbolic breadth first search.
 * 
 * At the end we can output the result to a dot diagram (this is only for debugging purpose of course)
 * \until mdd_unref
 * And don't forget to release the manager:
 * \until manager_free
 *
 * We should obtain the result:
 * \dot
 * graph G {
 * "(2|2)" [label = "x|<f0>2|<f1>3|<f2>4|<f3>5|<f4>6|<f5>7|<f6>8|<f7>9" shape = "record"]
 * "(2|2)":f2 -- "(0|1)"
 * "(2|2)":f4 -- "(0|1)"
 * "(2|2)":f6 -- "(0|1)"
 * "(0|1)" [label = "T" shape = "circle"]
 * }
 * \enddot
 *
 * To compile, put everything in file example.c and type:
 * \verbatim gcc example.c `pkg-config evmdd --cflags --libs` \endverbatim
 * and then execute with:
 * \verbatim ./a.out > state_space.dot && display state_space.dot \endverbatim
 *
 * The reader will find other examples in page examples.
 */
