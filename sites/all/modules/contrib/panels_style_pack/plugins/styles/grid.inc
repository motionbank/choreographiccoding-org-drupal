<?php

/**
 * @file
 * Definition of the 'Grid' panel style.
 */
// Plugin definition
$plugin = array(
  'title' => t('Grid'),
  'description' => t('Show panel panes in a region as Grid'),
  'render region' => 'panels_grid_style_render_region',
  'settings form' => 'panels_grid_style_settings_form',
);

function theme_panels_grid_style_render_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = array_values($vars['panes']);
  $settings = $vars['settings'];
  $tab_id = 'tabs-' . $owner_id . '-' . $region_id;

  $number = count($panes);
  $number_column = 2;
  if (isset($settings['number_column']) && is_numeric($settings['number_column'])) {
    $number_column = round($settings['number_column']);
  }
  if ($number % $number_column) {
    $number_row = ceil($number / $number_column);
  } else {
    $number_row = ($number / $number_column);
  }
  $k = 0;
  for ($i = 0; $i < $number_row; $i++) {
    for ($j = 0; $j < $number_column; $j++) {
      if (isset($panes[$k])) {
        $row[$i][$j] = $panes[$k];
        $k++;
      } else {
        if ($settings['fill_space'] === 0) {
          break;
        } else {
          if (($j % $number_column) === 0) {
            break;
          } else {
            $row[$i][$j] = '';
          }
        }
      }
    }
  }
  if (isset($row)) {
    $output = theme('grid', array('row' => $row));
  } else {
    $output = '';
  }
  return $output;
}

function panels_grid_style_settings_form($style_settings) {
  $form = array();

  $form['number_column'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of columns'),
    '#default_value' => $style_settings['number_column'],
    '#description' => t('Number of columns(defaulted to 2)'),
  );

  $form['fill_space'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fill Empty Space'),
    '#default_value' => $style_settings['fill_space'],
    '#description' => t('Tick if you want to fill out empty grid column space.')
  );
  return $form;
}