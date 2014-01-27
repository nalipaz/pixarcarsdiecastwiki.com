<?php

/**
 * Implementation of hook_views_query_alter
 * @param type $view
 * @param type $query
 */
function cars_misc_views_query_alter(&$view, &$query) {
  if ($view->name == 'release_glossary' && $view->current_display == 'attachment') {
    $query->fields['taxonomy_term_data_taxonomy_term_hierarchy_weight'] = array(
      'field' => 'weight',
      'table' => 'taxonomy_term_data_taxonomy_term_hierarchy',
      'alias' => 'taxonomy_term_data_taxonomy_term_hierarchy_weight',
    );

    $query->field_aliases['taxonomy_term_data_taxonomy_term_hierarchy'] = array(
      'weight' => 'taxonomy_term_data_taxonomy_term_hierarchy_weight',
    );

    $query->orderby[0]['field'] = 'taxonomy_term_data_taxonomy_term_hierarchy_weight';
  }
}
