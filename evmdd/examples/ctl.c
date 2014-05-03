t_mdd_level_index ctl_EX(t_mdd_manager *manager, t_mdd_level_index s)
{
  return mdd_prev(manager, s, mdd_manager_get_all_events(manager));
}

t_mdd_level_index ctl_EG(t_mdd_manager *manager, t_mdd_level_index s)
{
  t_mdd_level_index r=s, oldr, tmp;
  int nb_iterations=0;

  do {
    oldr = r;
    mdd_ref(manager, oldr);
    tmp = ctl_EX(manager, oldr);
    mdd_unref(manager, oldr);
    mdd_ref(manager, tmp);
    r = mdd_inter(manager, tmp, s);
    mdd_unref(manager, tmp);
    ++nb_iterations;
  } while (r != oldr);

  fprintf(stderr, "%s/%d: ctl_EG: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}

t_mdd_level_index ctl_EU(t_mdd_manager *manager, t_mdd_level_index s1, t_mdd_level_index s2)
{
  t_mdd_level_index r=s2, oldr, tmp;
  int nb_iterations=0;
  t_mdd_level_index s1Us2 = mdd_union(manager, s1, s2);

  mdd_ref(manager, s1Us2);
  do {
    oldr = r;
    mdd_ref(manager, oldr);
    tmp = mdd_add_prev(manager, oldr, mdd_manager_get_all_events(manager));
    mdd_unref(manager, oldr);
    mdd_ref(manager, tmp);
    r = mdd_inter(manager, tmp, s1Us2);
    mdd_unref(manager, tmp);
    ++nb_iterations;
  } while (r != oldr);
  mdd_unref(manager, s1Us2);

  fprintf(stderr, "%s/%d: ctl_EU: %d iterations\n", __FILE__, __LINE__, nb_iterations);

  return r;
}
