<?php


/**
 * @file
 * Definition of the 'Tabs' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Tabs'),
  'description' => t('Show panel panes in a region as tabs.'),
  'render region' => 'panels_style_pack_tabs_style_render_region',
  'settings form' => 'panels_style_pack_tabs_style_settings_form',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_style_pack_tabs_style_render_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];
  $settings_tabs = $vars['settings'];
  $tab_id = 'tabs-' . $owner_id . '-' . $region_id;
  
  if($settings_tabs['tab_type'] === 'horizontal' || $settings_tabs['tab_type'] === 'bottom') {
  $element = array(
    '#prefix' => '<div id="' . $tab_id . '">',
    '#suffix' => '</div>',
    '#attached' => array(
      'library' => array(array('system', 'ui.tabs')),
      'js' => array(
        drupal_get_path('module', 'panels_style_pack') . '/js/panels_style_pack.js' => array('type' => 'file'),
      ),
    ),
  );
  $settings = array();
  $settings['panelsTabs']['tab_style'] = $settings_tabs['tab_style'];
  $settings['panelsTabs']['tabsID'][] = $tab_id;
  $settings['type'] = 'tabs';
  $settings['panelsTabs']['orientation'] = $settings_tabs['tab_type'];

  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => $settings,
  );

  // Get the pane titles.
  $items = array();
  $delta = 1;
  foreach ($display->panels[$region_id] as $pane_id) {
    // Make sure the pane exists.
    if (!empty($panes[$pane_id])) {
      $title = panels_style_pack_pane_titles($display->did, $pane_id);
      $title = $title ? $title : t('Tab @delta', array('@delta' => $delta));
      $items[] = '<a href="#'. $tab_id . '-' . $delta .'">' . $title . '</a>';
      ++$delta;
    }
  }

  $element['tabs_title'] = array('#theme' => 'item_list', '#items' => $items);

  $items = array();
  $delta = 1;
  foreach ($panes as $pane_id => $item) {
    $element['tabs_content'][$pane_id] = array(
      '#prefix' => '<div id="' . $tab_id . '-' . $delta . '">',
      '#suffix' => '</div>',
      '#markup' => $item,
    );
    ++$delta;
  }
  if($settings_tabs['tab_type'] === 'bottom') {
  	$element['#prefix'] = '<div id="' . $tab_id . '" class="tabs-bottom">';
  	}
  return drupal_render($element);
  }
  else if($settings_tabs['tab_type'] === 'vertical_left') {
 
    $form['vertical_tabs'] = array(
    '#type' => 'vertical_tabs',
    '#tree' => TRUE,
  );
  
  $items = array();
  $delta = 1;
  foreach ($display->panels[$region_id] as $pane_id) {
    // Make sure the pane exists.
    if (!empty($panes[$pane_id])) {
      $title = panels_style_pack_pane_titles($display->did, $pane_id);
      $title = $title ? $title : t('Tab @delta', array('@delta' => $delta));
      $items[] = $title;
      ++$delta;
    }
  }
  foreach($panes as $pane_id => $item) {
  	 $pane = $display->content[$pane_id];
    $form['vertical_tabs'][$pane_id] = array(
      '#type' => 'fieldset',
      '#title' => $items[$pane_id-1],
      '#group' => 'vertical_tabs',
      '#tree' => TRUE,
    );
 
    $form['vertical_tabs'][$pane_id]['content'] = array(
     '#prefix' => '<div id="' . $tab_id . '-' . $delta . '">',
      '#suffix' => '</div>',
      '#markup' => $item,
    );
    ++$delta;
  }
  return drupal_render($form);
  }
}

function panels_style_pack_tabs_style_settings_form($style_settings) {
	$form = array();
	
	$form['tab_type'] = array(
    '#type' => 'select',
    '#title' => t('Tab Type'),
    '#default_value' => $style_settings['tab_type'],
    '#options' => array(
      'horizontal' => t('Horizontal'),
      'vertical_left' => t('Vertical Left'),
      'bottom' => t('Bottom'),
      ),
    '#description' => t('The type of tab'),
    );
    
    $form['tab_style'] = array(
    '#type' => 'select',
    '#title' => t('Tab Style'),
    '#default_value' => $style_settings['tab_style'],
    '#options' => array(
      'collapsible' => t('Collapsible'),
      'open_mouseover' => t('Open on mouseover'),
      ),
    '#description' => t('The Style of the tabs'),
    );
     return $form;
	}
