<?php

	/**
	* Implementation of hook_panels_styles().
	*/
	$plugin =  array(
	
		'sliding_region' => array(

			'title'		 	=> t('Region slideshow'),
			'description'   => t('A region as slideshow with panes as slides'),

			'render pane'   => 'sliding_region_pane',
			'render region' => 'sliding_region_region',

			'pane settings form'   => 'sliding_region_pane_settings_form',

			'hook theme' => array(

				'sliding_region_theme_pane' => array(
					'template' => 'sliding-region-pane',
					'path' => drupal_get_path('module', 'scrolling_panels_page') .'/plugins/styles/sliding_region',
					'variables' => array(
						'content' => NULL,
						'settings' => NULL,
					),
				),
				
				'sliding_region_theme_region' => array(
					'template' => 'sliding-region-region',
					'path' => drupal_get_path('module', 'scrolling_panels_page') .'/plugins/styles/sliding_region',
					'variables' => array(
						'content' => NULL
					),
				),

			),
		),
	);

	function theme_sliding_region_pane ( $vars ) 
	{
		$settings = $vars['settings'];

		if ( !empty( $settings['background_image'] ) && 
			 is_numeric( $settings['background_image']['fid'] ) )
		{
			$file = file_load( (int)$settings['background_image']['fid'] );
			$file->path = file_create_url( $file->uri );
			$style_paths = array();
			foreach ( image_styles() as $name => $istyle ) {
				$style_paths[$name] = array(
					'style' => $istyle,
					'path' => image_style_url( $name, $file->uri )
				);
			}
			$file->style_paths = $style_paths;
			$settings['background_image_file'] = (array)($file);
		}

		$content  = $vars['content'];

		return theme(
			'sliding_region_theme_pane',
			array(
				'content' => $content, 
				'settings' => $settings
			)
		);
	}

	function theme_sliding_region_region ( $vars )
	{
		$content = '';
	 
		foreach ($vars['panes'] as $pane_id => $pane_output)
		{
			$content .= $pane_output;
		}

		if ( empty( $content ) )
		{
			return;
		} 

		return theme(
			'sliding_region_theme_region',
			array(
				'content' => $content
			)
		);
	}
	 
	function sliding_region_pane_settings_form ( $style_settings )
	{	
		$image_fid = $style_settings['background_image'];
		//if ( empty($image_fid) ) $image_fid = variable_get( 'sliding_region_pane_background_image_fid', '' );

		$form['background_image'] = array(
		  '#title' 			=> t('Background image'),
		  '#description' 	=> t('Upload or select an image to be used as background for this slide/pane'),
		  '#default_value' 	=> $image_fid
		);

		if ( module_exists( 'media' ) ) 
		{
			$form['background_image'] = array_merge(
				$form['background_image'],
				array(
					'#type' => 'media',
				)
			);
		} 
		else 
		{
			$form['background_image'] = array_merge(
				$form['background_image'],
				array(
					'#type' => 'managed_file',
					'#upload_location' => 'public://region-slideshow/'
				)
			);
		}

		return $form;
	}
