<?php

/**
 * @file
 * Definition of the 'Tabs' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Accordion'),
  'description' => t('Show panel panes in a region as Accordion'),
  'render region' => 'panels_accordion_style_render_region',
  'settings form' => 'panels_accordion_style_settings_form',
);

function theme_panels_accordion_style_render_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];
  $style_settings = $vars['settings'];
  $tab_id = 'tabs-' . $owner_id . '-' . $region_id;
  
  $element['accordion_content'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="' . $tab_id . '">',
    '#suffix' => '</div>',
    '#attached' => array(
      'library' => array(array('system', 'ui.accordion')),
      'js' => array(
        drupal_get_path('module', 'panels_style_pack') . '/js/panels_style_pack.js' => array('type' => 'file'),
      ),
    ),
  );
  
  $settings = array();
  $settings['panelsAccordion']['accordionID'][] = $tab_id;
  $settings['panelsAccordion']['collapsible'] = $style_settings['collapsible'];
  $settings['panelsAccordion']['heightstyle'] = $style_settings['heightstyle'];
  
  $settings['type'] = 'accordion';
  

  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => $settings,
  );
  
  $items = array();
  $delta = 1;
  
  foreach ($panes as $pane_id => $item) {
  	 $title = $display->content[$pane_id]->configuration['title'];
    $element['accordion_content'][$pane_id] = array(
      '#prefix' => '<h3>' . $title . '</h3><div id="' . $tab_id . '-' . $delta . '">',
      '#suffix' => '</div>',
      '#markup' => $item,
    );
    ++$delta;
  }

  return drupal_render($element);
   }
   
function panels_accordion_style_settings_form($style_settings) {
 $form = array();
 
 $form['collapsible'] = array(
   '#type' => 'checkbox',
   '#title' => t('Collapsible'),
   '#default_value' => $style_settings['collapsible'],
   '#description' => t('Select if the acordion will be collapsible.')
  );
  
  $form['heightstyle'] = array(
    '#type' => 'select',
    '#title' => t('Height Style'),
    '#default_value' => $style_settings['heightstyle'],
    '#options' => array('fill' => 'Fill',
                        'content' => 'No Auto Height',
                        ),
    '#description' => t('Select an applicable heightstyle'),
    );
  return $form;
}