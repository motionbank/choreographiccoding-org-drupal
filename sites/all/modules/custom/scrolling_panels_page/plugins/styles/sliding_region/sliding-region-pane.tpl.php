<?php
	$bg_image_path = $bg_image_path_full = '';
	if ( !empty( $settings['background_image_file'] ) )
	{
		$bg_image_path = $settings['background_image_file']['style_paths']['large']['path'];
		//$bg_image_path_full = $settings['background_image_file']['path'];
		$bg_image_path_full = $settings['background_image_file']['style_paths']['frontpage_backgrounds']['path'];
	}
	$css_id = $css_class = '';
	if ( property_exists($content,'css_id') )
		$css_id = $content->css_id;
	if ( property_exists($content,'css_class') )
		$css_class = $content->css_class;
?><div class="pane <?php print $css_class ?>" 
	   style="background-image:url(<?php print $bg_image_path ?>)" 
		id="<?php print $css_id ?>"
		data-bg-img-full-path="<?php print $bg_image_path_full ?>">
	<div class="inner">
		<?php if (isset($content->title)): ?>
			<h2 class="pane-title"><?php print $content->title; ?></h2>
		<?php endif ?>
		<div class="pane-content">
			<?php print render($content->content); ?>
		</div>
	</div>
</div>