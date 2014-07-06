<?php


/**
 * @file
 * Definition of the 'Tabs' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Slideshow'),
  'description' => t('Show panel panes in a region as Slideshow.'),
  'render region' => 'panels_style_pack_slideshow_style_render_region',
  'settings form' => 'panels_style_pack_slideshow_style_settings_form',
);

function theme_panels_style_pack_slideshow_style_render_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];
  $conf = $vars['settings'];
  $tab_id = 'tabs-' . $owner_id . '-' . $region_id;
  
  $output = '<div id="'.$tab_id.'">';
  foreach($panes as $pane_id => $item) {
    $output .= '<div class="slide-'.$pane_id.'">'.$item.'</div>';
  }
  $output .= '</div>';
  
  if ($path = libraries_get_path('jquery.cycle')) {
   drupal_add_js($path . '/jquery.cycle.all.js');
  }
  else {
  return 'No jQuery cycle library found. Please download and install the library to use this style. See readme for download instructions.';
  	}
  if ($path = libraries_get_path('easing')) {
   drupal_add_js($path . '/jquery.easing.1.3.js');
  }
  drupal_add_js(drupal_get_path('module', 'panels_style_pack') .'/js/panels_style_pack.js');
  $settings = array();
  $settings['slideshow']['slideshowID'][] = $tab_id;
  $settings['type'] = 'slideshow';
  drupal_add_js(array('type' => 'slideshow',
                      'id' => $tab_id,
                      'transition_type' => $conf['transition_type'],
                      'easing' => $conf['easing'],
                      'timeout' => $conf['timeout'],
                      'prev' => $conf['prev'],
                      'next' => $conf['next'],
                      'pager' => $conf['pager'],
                      'timeoutfn' => explode(',', $conf['timeoutfn']),
                      'sync' => $conf['sync']), array('type' => 'setting'));
  return $output;
  }
  
  function panels_style_pack_slideshow_style_settings_form($style_settings) {
	$form = array();
	
	$options = drupal_map_assoc(array('none', 'blindX','blindY','blindZ', 'cover', 'curtainX', 'curtainY', 'fade', 'fadeZoom', 'growX', 'growY','scrollUp',
	 'scrollDown', 'scrollLeft', 'scrollRight', 'scrollHorz', 'scrollVert', 'shuffle', 'slideX', 'slideY', 'toss','turnUp',
    'turnDown', 'turnLeft','turnRight','uncover','wipe','zoom'));

	$form['transition_type'] = array(
    '#type' => 'select',
    '#title' => t('Transition Type'),
    '#default_value' => $style_settings['transition_type'],
    '#options' => $options,
    '#description' => t('Select a transition type.'),
    );
    
    if(libraries_get_path('easing')) {
    $options = drupal_map_assoc(array('jswing','def','easeInQuad','easeOutQuad','easeInOutQuad','easeInCubic','easeOutCubic',
'easeInOutCubic','easeInQuart','easeOutQuart','easeInOutQuart','easeInQuint','easeOutQuint',
'easeInOutQuint','easeInSine','easeOutSine','easeInOutSine','easeInExpo','easeOutExpo','easeInOutExpo',
'easeInCirc','easeOutCirc','easeInOutCirc','easeInElastic','easeOutElastic','easeInOutElastic','easeInBack',
'easeOutBack','easeInOutBack','easeInBounce','easeOutBounce','easeInOutBounce'));
    
    $form['easing'] = array(
    '#type' => 'select',
    '#title' => t('Easing Type'),
    '#default_value' => $style_settings['easing'],
    '#options' => $options,
    '#description' => t('Select a transition type.'),
    );
    
    }
    
    $form['sync'] = array(
    '#type' => 'select',
    '#title' => t('Sync'),
    '#default_value' => $style_settings['sync'],
    '#options' => array('0' => 'No',
                        '1' => 'Yes',
                        ),
    '#description' => t('Select whether to sync or not'),
    );
    
    $form['timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('timeout'),
    '#default_value' => $style_settings['timeout'],
    '#description' => t('Enter timeout value'),
    );
    
    $form['timeoutfn'] = array(
    '#type' => 'textfield',
    '#title' => t('timeout pre slide'),
    '#default_value' => $style_settings['timeoutfn'],
    '#description' => t('Enter timeout value per slide seperated by comma'),
    );
    
     $form['prev'] = array(
    '#type' => 'textfield',
    '#title' => t('Prev Selector ID'),
    '#default_value' => $style_settings['prev'],
    '#description' => t('Enter prev selector ID'),
    );
    
     $form['next'] = array(
    '#type' => 'textfield',
    '#title' => t('next selector ID'),
    '#default_value' => $style_settings['next'],
    '#description' => t('Enter next selector ID'),
    );
    
     $form['pager'] = array(
    '#type' => 'textfield',
    '#title' => t('Pager ID'),
    '#default_value' => $style_settings['pager'],
    '#description' => t('Enter pager ID'),
    );
    
    return $form;
	}
