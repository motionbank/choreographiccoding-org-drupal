<?php
/**
 * @file
 * scrolling_front_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scrolling_front_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scrolling_front_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scrolling_front_page_node_info() {
  $items = array(
    'lab' => array(
      'name' => t('Lab'),
      'base' => 'node_content',
      'description' => t('A choreographic coding lab'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('A project that was realized or started during a CCL'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
