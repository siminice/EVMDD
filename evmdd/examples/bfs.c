t_mdd_level_index bfs(t_mdd_manager *manager, t_mdd_level_index s)
{
  t_mdd_level_index r=s, prevr, oldr;
  t_event_entry *e, **events=mdd_manager_get_events(manager);
  int k, nb_levels=mdd_manager_get_nb_levels(manager);
  int nb_iterations=0;

  do {
    oldr = r;
    for (k = 1; k <= nb_levels; ++k) {
      e = events[k];
      while (e) {
        prevr = r;
        mdd_ref(manager, prevr);
        r = mdd_add_next(manager, prevr, e->data);
        mdd_unref(manager, prevr);
        e = e->next;
      }
    }
    ++nb_iterations;
    fprintf(stderr, "%s/%d: BFS: iteration #%d completed\n", __FILE__, __LINE__, nb_iterations);
  } while (r != oldr);

  fprintf(stderr, "%s/%d: BFS: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}
