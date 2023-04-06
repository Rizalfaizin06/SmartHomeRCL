<?php
defined('BASEPATH') or exit('No direct script access allowed');
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="<?= base_url() ?>assets/bootstrap/css/bootstrap.min.css" rel="stylesheet">
    <title>Home</title>
</head>

<body>
    <nav class="navbar navbar-expand-md bg-light sticky-top">
        <div class="container">
            <a class="navbar-brand" href="<?= base_url() ?>">Rizals Company Lab</a>
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNavAltMarkup"
                aria-controls="navbarNavAltMarkup" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
                <div class="navbar-nav">
                    <a class="nav-link" aria-current="page" href="<?= base_url() ?>">Home</a>
                    <a class="nav-link">Profile</a>
                </div>
            </div>
        </div>
    </nav>

    <div class="container mt-3">
        <h1>My Devices</h1>

        <div class="row mt-1">
            <div class="col-md-10">
                <table class="table table-hover">
                    <thead>
                        <tr>
                            <th>No.</th>
                            <th>ID</th>
                            <th>Device</th>
                            <th>Status</th>
                            <th>Action</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php
                        $count = 1;
                        foreach ($devices->result() as $row):
                            ?>
                            <tr>
                                <td>
                                    <?= $count; ?>
                                </td>
                                <td>
                                    <?= $row->id; ?>
                                </td>
                                <td>
                                    <?= $row->name; ?>
                                </td>
                                <td>
                                    <?= $row->status; ?>
                                </td>
                                <td>
                                    <form action="<?= base_url() ?>home/update" method="post">
                                        <div class="input-group mb-3">
                                            <input type="hidden" name="idDevices" value="<?= $row->id; ?>"
                                                class="form-control" placeholder="Search Product Code">
                                            <input type="submit" name="submit" value="submit" class="btn btn-primary">
                                        </div>
                                    </form>
                                </td>
                                <?php $count++; endforeach; ?>
                        </tr>
                    </tbody>
                </table>

            </div>
        </div>

    </div>
    <script src="<?= base_url() ?>assets/bootstrap/js/bootstrap.bundle.min.js">
    </script>
</body>

</html>